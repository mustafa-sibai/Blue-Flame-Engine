#pragma once
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include <fbxsdk/fbxsdk_version.h>
#include <vector>
#include <algorithm>
#include <BF/Math/Math.h>
#include <BF/Graphics/Mesh.h>

//#include "BF/Graphics/Material.h"

namespace Editor
{
	namespace IO
	{
		class FBXLoader
		{
			public:
				enum class ImportSettings { ImportP, ImportPN, ImportPUV, ImportPUVN, ImportPUVNTB };

			private:
				std::vector<BF::Math::Vector3f> controlPoints;
				std::vector<void*> vertices;
				std::vector<unsigned int> indices;
				//std::vector<Graphics::Material>* materials;
				unsigned int triCount;
				std::vector<BF::Graphics::MeshData> meshesData;

			public:
				FBXLoader();
				~FBXLoader();
				void Load(const char* filename, ImportSettings importSettings);

				const std::vector<BF::Graphics::MeshData>& GetMeshsData() const { return meshesData; }

			private:
				FbxAMatrix GetNodeTransform(FbxNode *pNode);
				void ReadControlPoints(FbxMesh* mesh);
				void ProcessMesh(FbxMesh* mesh, ImportSettings importSettings);
				BF::Math::Vector3f ReadNormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter, bool& hasNormals);
				BF::Math::Vector3f ReadTangent(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter, bool& hasTangent);
				BF::Math::Vector3f ReadBinormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter, bool& hasBinormal);
				BF::Math::Vector2f ReadUV(FbxMesh* inMesh, int inCtrlPointIndex, int inTextureUVIndex, int inUVLayer, bool& hasUV);
				//void LoadUVInformation(FbxMesh* pMesh);

				//void ProcessMaterials(FbxNode* inNode);
				//void AssociateMaterialToMesh(FbxMesh* mesh);
				//void ProcessMaterialTexture(FbxSurfaceMaterial* inMaterial, Graphics::Material* material);
		};
	}
}