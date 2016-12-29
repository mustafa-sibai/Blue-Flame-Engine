#pragma once
#include <fbxsdk.h>
#include <fbxsdk/fileio/fbxiosettings.h>
#include <fbxsdk/fbxsdk_version.h>
#include <vector>
#include <algorithm>
#include <BF/Math/Math.h>
#include <BF/Graphics/Mesh.h>

//#include "BF/Graphics/Material.h"

class FBXLoader
{
private:
	std::vector<BF::Math::Vector3>* controlPoints;
	std::vector<BF::Graphics::MeshVertexData>* vertices;
	std::vector<unsigned int>* indices;
	//std::vector<Graphics::Material>* materials;
	unsigned int triCount;
	std::vector<BF::Graphics::Mesh>* meshes;

public:
	FBXLoader();
	~FBXLoader();
	void Load(const char* filename);

	const std::vector<BF::Graphics::Mesh>* GetMeshs() const { return meshes; }

private:
	FbxAMatrix GetNodeTransform(FbxNode *pNode);
	void ReadControlPoints(FbxMesh* mesh);
	void ProcessMesh(FbxMesh* mesh);
	BF::Math::Vector3 ReadNormal(FbxMesh* inMesh, int inCtrlPointIndex, int inVertexCounter);
	BF::Math::Vector2 ReadUV(FbxMesh* inMesh, int inCtrlPointIndex, int inTextureUVIndex, int inUVLayer);
	//void LoadUVInformation(FbxMesh* pMesh);

	//void ProcessMaterials(FbxNode* inNode);
	//void AssociateMaterialToMesh(FbxMesh* mesh);
	//void ProcessMaterialTexture(FbxSurfaceMaterial* inMaterial, Graphics::Material* material);
};