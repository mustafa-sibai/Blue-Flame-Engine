#include "FBXLoader.h"

namespace BF
{
	namespace IO
	{
		FBXLoader::FBXLoader()
		{
		}

		FBXLoader::~FBXLoader()
		{
		}

		FbxAMatrix FBXLoader::GetNodeTransform(FbxNode *pNode)
		{
			FbxVector4 t = pNode->GetGeometricTranslation(FbxNode::eSourcePivot);
			FbxVector4 s = pNode->GetGeometricScaling(FbxNode::eSourcePivot);
			FbxVector4 r = pNode->GetGeometricRotation(FbxNode::eSourcePivot);
			FbxAMatrix offset(t, r, s);
			FbxAMatrix world = pNode->EvaluateGlobalTransform();
			FbxAMatrix transform = world * offset;

			return transform;
		}

		void FBXLoader::Load(const char* filename)
		{
			controlPoints = new std::vector<Math::Vector3>();
			materials = new std::vector<Graphics::Material>();

			meshes = new std::vector<Graphics::Mesh>();


	
			FbxManager* lSdkManager = FbxManager::Create();
			printf("FBX version %s\n", FBXSDK_VERSION_STRING_FULL);

			FbxIOSettings* ios = FbxIOSettings::Create(lSdkManager, IOSROOT);
			lSdkManager->SetIOSettings(ios);


			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_MODEL, true);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_MATERIAL, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_TEXTURE, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_LINK, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_SHAPE, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_GOBO, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_ANIMATION, false);
			(*(lSdkManager->GetIOSettings())).SetBoolProp(IMP_FBX_GLOBAL_SETTINGS, true);


			FbxImporter* lImporter = FbxImporter::Create(lSdkManager, "");
			if (!lImporter->Initialize(filename, -1, lSdkManager->GetIOSettings()))
			{
				printf("Call to FbxImporter::Initialize() failed.\n");
				printf("Error returned: %s\n\n", lImporter->GetStatus().GetErrorString());
			}
			else
				printf("Loaded FBX FILE !!\n");

			FbxScene* lScene = FbxScene::Create(lSdkManager, "");
			lImporter->Import(lScene);

			int lFileMajor, lFileMinor, lFileRevision;
			lImporter->GetFileVersion(lFileMajor, lFileMinor, lFileRevision);

			printf("FBX file version %d.%d.%d\n", lFileMajor, lFileMinor, lFileRevision);

			FbxNode* rootNode = lScene->GetRootNode();

			int childCount = rootNode->GetChildCount();
			for (int i = 0; i < childCount; i++)
			{
				FbxNode* node = rootNode->GetChild(i);
				FbxNodeAttribute* lNodeAttribute = node->GetNodeAttribute();

				if (lNodeAttribute)
				{
					if (lNodeAttribute->GetAttributeType() == FbxNodeAttribute::eMesh)
					{
						vertices = new std::vector<Graphics::MeshVertexData>();
						indices = new std::vector<unsigned int>();
						materials = new std::vector<Graphics::Material>();
						controlPoints->clear();

						FbxGeometryConverter lConverter(node->GetFbxManager());
						lConverter.Triangulate(lScene, true, false);

						FbxMesh* mesh = node->GetMesh();


						mesh->SetPivot(GetNodeTransform(node));
						mesh->ApplyPivot();

						ProcessMaterials(node);
						
						//LoadUVInformation(mesh);



						ReadControlPoints(mesh);
						ProcessMesh(mesh);
						AssociateMaterialToMesh(mesh);
					}
				}
			}

			//mesh->SetPivot(GetNodeTransform(node));
			//mesh->ApplyPivot();
			//node->SetGeometricTranslation(transform->settrtransform = GetNodeTransform(pNode);

			//printf("%d\n", mesh->GetPolygonCount());
			//printf("%d\n", mesh->GetPolygonVertexCount());

			lImporter->Destroy();
		}

		void FBXLoader::ReadControlPoints(FbxMesh* mesh)
		{
			int controlPointsCount = mesh->GetControlPointsCount();
			FbxVector4* pControlPoints = mesh->GetControlPoints();

			for (int i = 0; i < controlPointsCount; i++)
				controlPoints->push_back(BF::Math::Vector3((float)pControlPoints[i].mData[0] * 0.01f, (float)pControlPoints[i].mData[1] * 0.01f, (float)pControlPoints[i].mData[2] * 0.01f));
		}

		void FBXLoader::ProcessMesh(FbxMesh* mesh)
		{
			int vertexCounter = 0;
			int ctrlPointIndex;
			triCount = mesh->GetPolygonCount();

			for (unsigned int i = 0; i < triCount; i++)
			{
				for (unsigned int j = 0; j < 3; j++)
				{
					ctrlPointIndex = mesh->GetPolygonVertex(i, j);

					Math::Vector3 normal = ReadNormal(mesh, ctrlPointIndex, vertexCounter);
					Math::Vector2 UV;

					for (int k = 0; k < 1; k++)
						UV = ReadUV(mesh, ctrlPointIndex, mesh->GetTextureUVIndex(i, j), k);

					vertices->push_back(BF::Graphics::MeshVertexData(controlPoints[0][ctrlPointIndex], UV, normal, 0));
					indices->push_back(vertexCounter);
					vertexCounter++;
				}
			}

			//for (unsigned int i = 0; i < vertices->size(); ++i)
			//	std::cout << "v: " << vertices[0][i].position << " n: " << vertices[0][i].normal << std::endl;

			meshes->push_back(BF::Graphics::Mesh(vertices, indices, materials));
		}

		Math::Vector3 FBXLoader::ReadNormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter)
		{
			if (inMesh->GetElementNormalCount() < 1)
				std::cout << "Invalid Normal Number" << std::endl;

			BF::Math::Vector3 outNormal;

			FbxGeometryElementNormal* vertexNormal = inMesh->GetElementNormal(0);
			switch (vertexNormal->GetMappingMode())
			{
			case FbxGeometryElement::eByControlPoint:
				switch (vertexNormal->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outNormal.x = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[0]);
					outNormal.y = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[1]);
					outNormal.z = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexNormal->GetIndexArray().GetAt(inCtrlPointIndex);
					outNormal.x = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[0]);
					outNormal.y = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[1]);
					outNormal.z = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;

			case FbxGeometryElement::eByPolygonVertex:
				switch (vertexNormal->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outNormal.x = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[0]);
					outNormal.y = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[1]);
					outNormal.z = static_cast<float>(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexNormal->GetIndexArray().GetAt(inVertexCounter);
					outNormal.x = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[0]);
					outNormal.y = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[1]);
					outNormal.z = static_cast<float>(vertexNormal->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;
			}

			return outNormal;
		}

		Math::Vector2 FBXLoader::ReadUV(FbxMesh* inMesh, int inCtrlPointIndex, int inTextureUVIndex, int inUVLayer)
		{
			if (inUVLayer >= 2 || inMesh->GetElementUVCount() <= inUVLayer)
			{
				throw std::exception("Invalid UV Layer Number");
			}
			FbxGeometryElementUV* vertexUV = inMesh->GetElementUV(inUVLayer);

			Math::Vector2 outUV;

			switch (vertexUV->GetMappingMode())
			{
				case FbxGeometryElement::eByControlPoint:
				{
					switch (vertexUV->GetReferenceMode())
					{
						case FbxGeometryElement::eDirect:
						{
							outUV.x = static_cast<float>(vertexUV->GetDirectArray().GetAt(inCtrlPointIndex).mData[0]);
							outUV.y = static_cast<float>(vertexUV->GetDirectArray().GetAt(inCtrlPointIndex).mData[1]);
							break;
						}

						case FbxGeometryElement::eIndexToDirect:
						{
							int index = vertexUV->GetIndexArray().GetAt(inCtrlPointIndex);
							outUV.x = static_cast<float>(vertexUV->GetDirectArray().GetAt(index).mData[0]);
							outUV.y = static_cast<float>(vertexUV->GetDirectArray().GetAt(index).mData[1]);
							break;
						}

						default:
						{
							throw std::exception("Invalid Reference");
							break;
						}
					}
					break;
				}

				case FbxGeometryElement::eByPolygonVertex:
				{
					switch (vertexUV->GetReferenceMode())
					{
						case FbxGeometryElement::eDirect:
						{
							break;
						}

						case FbxGeometryElement::eIndexToDirect:
						{
							outUV.x = static_cast<float>(vertexUV->GetDirectArray().GetAt(inTextureUVIndex).mData[0]);
							outUV.y = 1.0f - static_cast<float>(vertexUV->GetDirectArray().GetAt(inTextureUVIndex).mData[1]);
							break;
						}

						default:
						{
							throw std::exception("Invalid Reference");
							break;
						}
					}
					break;
				}
			}

			return outUV;
		}

		void FBXLoader::AssociateMaterialToMesh(FbxMesh* mesh)
		{
			FbxLayerElementArrayTemplate<int>* materialIndices;
			FbxGeometryElement::EMappingMode materialMappingMode = FbxGeometryElement::eNone;

			if (mesh->GetElementMaterial())
			{
				materialIndices = &(mesh->GetElementMaterial()->GetIndexArray());
				materialMappingMode = mesh->GetElementMaterial()->GetMappingMode();

				if (materialIndices)
				{
					switch (materialMappingMode)
					{
					case FbxGeometryElement::eByPolygon:
					{
						std::cout << materialIndices->GetCount() << std::endl;
						if (materialIndices->GetCount() == triCount)
						{
							for (unsigned int i = 0; i < triCount; i++)
							{
								unsigned int materialIndex = materialIndices->GetAt(i);
								for (unsigned int j = 0; j < 3; j++)
									vertices[0][j + (i * 3)].textureID = materialIndex;
							}
						}
					}
					break;

					case FbxGeometryElement::eAllSame:
					{
						unsigned int materialIndex = materialIndices->GetAt(0);
						for (unsigned int i = 0; i < triCount; i++)
						{
							for (unsigned int j = 0; j < 3; j++)
								vertices[0][j + (i * 3)].textureID = materialIndex;
						}
					}
					break;

					default:
						throw std::exception("Invalid mapping mode for material\n");
					}
				}
			}
		}


		void FBXLoader::ProcessMaterials(FbxNode* inNode)
		{
			unsigned int materialCount = inNode->GetMaterialCount();

			for (unsigned int i = 0; i < materialCount; ++i)
			{
				materials->push_back(Graphics::Material("", Math::Vector4()));
				FbxSurfaceMaterial* surfaceMaterial = inNode->GetMaterial(i);
				ProcessMaterialTexture(surfaceMaterial, &materials[0][i]);
			}
		}

		void FBXLoader::ProcessMaterialTexture(FbxSurfaceMaterial* inMaterial, Graphics::Material* material)
		{
			unsigned int textureIndex = 0;
			FbxProperty property;

			FBXSDK_FOR_EACH_TEXTURE(textureIndex)
			{
				property = inMaterial->FindProperty(FbxLayerElement::sTextureChannelNames[textureIndex]);
				if (property.IsValid())
				{
					unsigned int textureCount = property.GetSrcObjectCount<FbxTexture>();
					for (unsigned int i = 0; i < textureCount; ++i)
					{
						FbxLayeredTexture* layeredTexture = property.GetSrcObject<FbxLayeredTexture>(i);
						if (layeredTexture)
						{
							throw std::exception("Layered Texture is currently unsupported\n");
						}
						else
						{
							FbxTexture* texture = property.GetSrcObject<FbxTexture>(i);
							if (texture)
							{
								std::string textureType = property.GetNameAsCStr();
								FbxFileTexture* fileTexture = FbxCast<FbxFileTexture>(texture);

								if (fileTexture)
								{
									if (textureType == "DiffuseColor")
									{
										material->diffuseMapName = fileTexture->GetFileName();
									}
									else if (textureType == "SpecularColor")
									{
										std::cout << fileTexture->GetFileName() << std::endl;
									}
									else if (textureType == "Bump")
									{
										std::cout << fileTexture->GetFileName() << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


/*
		void FBXLoader::LoadUVInformation(FbxMesh* pMesh)
		{
			//get all UV set names
			FbxStringList lUVSetNameList;
			pMesh->GetUVSetNames(lUVSetNameList);

			//iterating over all uv sets
			for (int lUVSetIndex = 0; lUVSetIndex < lUVSetNameList.GetCount(); lUVSetIndex++)
			{
				//get lUVSetIndex-th uv set
				const char* lUVSetName = lUVSetNameList.GetStringAt(lUVSetIndex);
				const FbxGeometryElementUV* lUVElement = pMesh->GetElementUV(lUVSetName);

				if (!lUVElement)
					continue;

				// only support mapping mode eByPolygonVertex and eByControlPoint
				if (lUVElement->GetMappingMode() != FbxGeometryElement::eByPolygonVertex &&
					lUVElement->GetMappingMode() != FbxGeometryElement::eByControlPoint)
					return;

				//index array, where holds the index referenced to the uv data
				const bool lUseIndex = lUVElement->GetReferenceMode() != FbxGeometryElement::eDirect;
				const int lIndexCount = (lUseIndex) ? lUVElement->GetIndexArray().GetCount() : 0;

				//iterating through the data by polygon
				const int lPolyCount = pMesh->GetPolygonCount();

				if (lUVElement->GetMappingMode() == FbxGeometryElement::eByControlPoint)
				{
					for (int lPolyIndex = 0; lPolyIndex < lPolyCount; ++lPolyIndex)
					{
						// build the max index array that we need to pass into MakePoly
						const int lPolySize = pMesh->GetPolygonSize(lPolyIndex);
						for (int lVertIndex = 0; lVertIndex < lPolySize; ++lVertIndex)
						{
							FbxVector2 lUVValue;

							//get the index of the current vertex in control points array
							int lPolyVertIndex = pMesh->GetPolygonVertex(lPolyIndex, lVertIndex);

							//the UV index depends on the reference mode
							int lUVIndex = lUseIndex ? lUVElement->GetIndexArray().GetAt(lPolyVertIndex) : lPolyVertIndex;

							lUVValue = lUVElement->GetDirectArray().GetAt(lUVIndex);

							//User TODO:
							//Print out the value of UV(lUVValue) or log it to a file
						}
					}
				}
				else if (lUVElement->GetMappingMode() == FbxGeometryElement::eByPolygonVertex)
				{
					int lPolyIndexCounter = 0;
					for (int lPolyIndex = 0; lPolyIndex < lPolyCount; ++lPolyIndex)
					{
						// build the max index array that we need to pass into MakePoly
						const int lPolySize = pMesh->GetPolygonSize(lPolyIndex);
						for (int lVertIndex = 0; lVertIndex < lPolySize; ++lVertIndex)
						{
							if (lPolyIndexCounter < lIndexCount)
							{
								FbxVector2 lUVValue;

								//the UV index depends on the reference mode
								int lUVIndex = lUseIndex ? lUVElement->GetIndexArray().GetAt(lPolyIndexCounter) : lPolyIndexCounter;

								lUVValue = lUVElement->GetDirectArray().GetAt(lUVIndex);

								//User TODO:
								//Print out the value of UV(lUVValue) or log it to a file

								lPolyIndexCounter++;
							}
						}
					}
				}
			}
		}
		*/