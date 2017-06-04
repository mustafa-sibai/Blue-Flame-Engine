#include "FBXLoader.h"

namespace Editor
{
	namespace IO
	{
		using namespace BF::Math;
		using namespace BF::Graphics;

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
			controlPoints = new std::vector<Vector3>();
			//materials = new std::vector<Graphics::Material>();

			meshes = new std::vector<Mesh>();


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
						vertices = new std::vector<MeshVertexData>();
						indices = new std::vector<unsigned int>();
						//materials = new std::vector<Material>();
						controlPoints->clear();

						FbxGeometryConverter lConverter(node->GetFbxManager());
						lConverter.Triangulate(lScene, true, false);

						FbxMesh* mesh = node->GetMesh();

						mesh->SetPivot(GetNodeTransform(node));
						mesh->ApplyPivot();

						//ProcessMaterials(node);

						//LoadUVInformation(mesh);

						ReadControlPoints(mesh);
						ProcessMesh(mesh);
						//AssociateMaterialToMesh(mesh);
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
				controlPoints->push_back(Vector3((float)pControlPoints[i].mData[0] * 0.01f, (float)pControlPoints[i].mData[1] * 0.01f, (float)pControlPoints[i].mData[2] * 0.01f));
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

					Vector3 normal = ReadNormal(mesh, ctrlPointIndex, vertexCounter);
					Vector3 tangent = ReadTangent(mesh, ctrlPointIndex, vertexCounter);
					Vector3 binormal = ReadBinormal(mesh, ctrlPointIndex, vertexCounter);
					Vector2 UV;

					for (int k = 0; k < 1; k++)
						UV = ReadUV(mesh, ctrlPointIndex, mesh->GetTextureUVIndex(i, j), k);

					MeshVertexData vertex(controlPoints[0][ctrlPointIndex], UV, normal, tangent, binormal);

					/*if (vertices->size() > 0)
					{
						int index = std::find(vertices->begin(), vertices->end(), vertex) - vertices->begin();

						if (index >= vertices->size())
						{
							vertices->push_back(vertex);
							indices->push_back(vertexCounter);
							vertexCounter++;
						}
						else
						{
							indices->push_back(index);
						}
					}
					else
					{*/
					vertices->push_back(vertex);
					indices->push_back(vertexCounter);
					vertexCounter++;
					//}
				}
			}

			/*
			for (unsigned int i = 0; i < vertices->size(); ++i)
				std::cout << "v: " << vertices[0][i].position << " n: " << vertices[0][i].normal << std::endl;

			for (unsigned int i = 0; i < indices->size(); ++i)
				std::cout << "i: " << indices[0][i] << std::endl;*/

			meshes->push_back(Mesh(vertices, indices/*, materials*/));
		}

		Vector3 FBXLoader::ReadNormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter)
		{
			if (inMesh->GetElementNormalCount() < 1)
				std::cout << "Invalid Normal Number" << std::endl;

			Vector3 outNormal;

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

					outNormal.x = static_cast<float>(round(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[0]));
					outNormal.y = static_cast<float>(round(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[1]));
					outNormal.z = static_cast<float>(round(vertexNormal->GetDirectArray().GetAt(inVertexCounter).mData[2]));
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

		Vector3 FBXLoader::ReadTangent(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter)
		{
			if (inMesh->GetElementTangentCount() < 1)
			{
				std::cout << "Invalid Tangent Number" << std::endl;
				return Vector3();
			}

			Vector3 outTangent;

			FbxGeometryElementTangent* vertexTangent = inMesh->GetElementTangent(0);
			switch (vertexTangent->GetMappingMode())
			{
			case FbxGeometryElement::eByControlPoint:
				switch (vertexTangent->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outTangent.x = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inCtrlPointIndex).mData[0]);
					outTangent.y = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inCtrlPointIndex).mData[1]);
					outTangent.z = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inCtrlPointIndex).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexTangent->GetIndexArray().GetAt(inCtrlPointIndex);
					outTangent.x = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[0]);
					outTangent.y = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[1]);
					outTangent.z = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;

			case FbxGeometryElement::eByPolygonVertex:
				switch (vertexTangent->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outTangent.x = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inVertexCounter).mData[0]);
					outTangent.y = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inVertexCounter).mData[1]);
					outTangent.z = static_cast<float>(vertexTangent->GetDirectArray().GetAt(inVertexCounter).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexTangent->GetIndexArray().GetAt(inVertexCounter);
					outTangent.x = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[0]);
					outTangent.y = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[1]);
					outTangent.z = static_cast<float>(vertexTangent->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;
			}

			return outTangent;
		}

		Vector3 FBXLoader::ReadBinormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter)
		{
			if (inMesh->GetElementBinormalCount() < 1)
			{
				std::cout << "Invalid Binormal Number" << std::endl;
				return Vector3();
			}

			Vector3 outBinormal;

			FbxGeometryElementBinormal* vertexBinormal = inMesh->GetElementBinormal(0);
			switch (vertexBinormal->GetMappingMode())
			{
			case FbxGeometryElement::eByControlPoint:
				switch (vertexBinormal->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outBinormal.x = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[0]);
					outBinormal.y = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[1]);
					outBinormal.z = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inCtrlPointIndex).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexBinormal->GetIndexArray().GetAt(inCtrlPointIndex);
					outBinormal.x = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[0]);
					outBinormal.y = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[1]);
					outBinormal.z = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;

			case FbxGeometryElement::eByPolygonVertex:
				switch (vertexBinormal->GetReferenceMode())
				{
				case FbxGeometryElement::eDirect:
				{
					outBinormal.x = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inVertexCounter).mData[0]);
					outBinormal.y = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inVertexCounter).mData[1]);
					outBinormal.z = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(inVertexCounter).mData[2]);
				}
				break;

				case FbxGeometryElement::eIndexToDirect:
				{
					int index = vertexBinormal->GetIndexArray().GetAt(inVertexCounter);
					outBinormal.x = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[0]);
					outBinormal.y = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[1]);
					outBinormal.z = static_cast<float>(vertexBinormal->GetDirectArray().GetAt(index).mData[2]);
				}
				break;

				default:
					std::cout << "Invalid Reference" << std::endl;
				}
				break;
			}

			return outBinormal;
		}

		Vector2 FBXLoader::ReadUV(FbxMesh* inMesh, int inCtrlPointIndex, int inTextureUVIndex, int inUVLayer)
		{
			if (inUVLayer >= 2 || inMesh->GetElementUVCount() <= inUVLayer)
			{
				return Vector2();
				//throw std::exception("Invalid UV Layer Number");
			}
			FbxGeometryElementUV* vertexUV = inMesh->GetElementUV(inUVLayer);

			Vector2 outUV;

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
	}
}