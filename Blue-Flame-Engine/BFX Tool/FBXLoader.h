#pragma once
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include <fbxsdk/fbxsdk_version.h>
#include "BF/Graphics/Mesh.h"
#include "BF/Graphics/Material.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API FBXLoader
		{
			private:
				std::vector<Math::Vector3>* controlPoints;

			public:
				std::vector<Graphics::Mesh>* meshes;
				std::vector<Graphics::MeshVertexData>* vertices;
				std::vector<unsigned int>* indices;
				std::vector<Graphics::Material>* materials;
				unsigned int triCount;

			public:
				FBXLoader();
				~FBXLoader();
				void Load(const char* filename);

			private:
				FbxAMatrix GetNodeTransform(FbxNode *pNode);
				void ReadControlPoints(FbxMesh* mesh);
				void ProcessMesh(FbxMesh* mesh);
				Math::Vector3 ReadNormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter);
				Math::Vector2 ReadUV(FbxMesh* inMesh, int inCtrlPointIndex, int inTextureUVIndex, int inUVLayer);
				void LoadUVInformation(FbxMesh* pMesh);

				void ProcessMaterials(FbxNode* inNode);
				void AssociateMaterialToMesh(FbxMesh* mesh);
				void ProcessMaterialTexture(FbxSurfaceMaterial* inMaterial, Graphics::Material* material);
		};
	}
}