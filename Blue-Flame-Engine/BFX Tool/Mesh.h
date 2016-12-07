#pragma once
#include <vector>
#include"Math/Vector2.h"
#include"Math/Vector3.h"
#include"Math/Vector4.h"

//#include "Material.h"

struct MeshVertexData
{
	Vector3 position;
	Vector2 texcoord;
	Vector3 normal;

	MeshVertexData() :
		position(0), texcoord(0), normal(0) { }

	MeshVertexData(Vector3 position, Vector2 texcoord, Vector3 normal) :
		position(position), texcoord(texcoord), normal(normal)
	{
	}
};

class Mesh
{
private:
	//std::vector<API::Texture2D*>* textures;
	const std::vector<MeshVertexData>* vertices;
	//std::vector<Material>* materials;
	const std::vector<unsigned int>* indices;

public:
	Mesh();
	Mesh(const std::vector<MeshVertexData>* vertices, const std::vector<unsigned int>* indices/*, std::vector<Material>* materials*/);
	~Mesh();

	inline const std::vector<MeshVertexData>* GetVertices() const { return vertices; }
	inline const std::vector<unsigned int>* GetIndices() const { return indices; }
};