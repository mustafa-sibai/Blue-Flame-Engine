#include "Mesh.h"

Mesh::Mesh()
{
}

Mesh::Mesh(const std::vector<MeshVertexData>* vertices, const std::vector<unsigned int>* indices/*, std::vector<Material>* materials*/) :
	/*textures(nullptr),*/ vertices(vertices), indices(indices)/*, materials(materials),*/
{
}

Mesh::~Mesh()
{
}