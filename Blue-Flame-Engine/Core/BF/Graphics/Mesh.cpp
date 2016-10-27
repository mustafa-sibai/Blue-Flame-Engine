#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Mesh::Mesh(vector<MeshVertexData>* vertices, vector<unsigned int>* indices) :
			buffer(nullptr), indexBuffer(nullptr), vertices(vertices), indices(indices)
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(API::Context* context, API::Shader* shader)
		{
			buffer = new VertexBuffer(context, shader);
			indexBuffer = new IndexBuffer(context);

			buffer->Create(&vertices[0][0], (unsigned int)vertices->size() * sizeof(MeshVertexData));
			indexBuffer->Create(&indices[0][0], (unsigned int)indices->size());
		}

		void Mesh::Bind() const
		{
			indexBuffer->Bind();
		}

		void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
		}
	}
}