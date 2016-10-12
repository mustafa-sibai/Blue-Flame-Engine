#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		Mesh::Mesh(std::vector<Vertex> *vertices, std::vector<unsigned int> *indices) :
			buffer(nullptr), indexBuffer(nullptr), vertexBufferLayout(nullptr), vertices(vertices), indices(indices)
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(API::Context *context, API::Shader *shader)
		{
			buffer = new API::VertexBuffer(context, shader);
			indexBuffer = new API::IndexBuffer(context);
			vertexBufferLayout = new API::VertexBufferLayout();

			buffer->Create(&vertices[0][0], (unsigned int)vertices->size() * sizeof(Vertex));
			indexBuffer->Create(&indices[0][0], (unsigned int)indices->size());

			vertexBufferLayout->Push(0, "POSITION", API::DataType::Float3, sizeof(Vertex), 0);
			//vertexBufferLayout->Push(1, "COLOR", DataType::Float4, sizeof(BF::IO::Vertex), 0);
			vertexBufferLayout->Push(2, "TEXCOORD", API::DataType::Float2, sizeof(Vertex), sizeof(BF::Math::Vector3));

			buffer->SetLayout(vertexBufferLayout);
		}

		const void Mesh::Bind() const
		{
			buffer->Bind();
			indexBuffer->Bind();
		}

		const void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
			buffer->Unbind();
		}
	}
}