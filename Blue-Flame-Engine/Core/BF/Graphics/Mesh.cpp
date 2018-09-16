#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Graphics::API;

		Mesh::Mesh(void* vertices, vector<unsigned int>& indices, VertexStructVersion vertexStructVersion) :
			vertexBuffer(nullptr), indexBuffer(nullptr), vertices(vertices), indices(indices), vertexStructVersion(vertexStructVersion)
		{
			Component::type = Component::Type::Mesh;
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers()
		{
			vertexBuffer = new VertexBuffer(material->shader);
			indexBuffer = new IndexBuffer();

			unsigned int vertexStructSize = 0;

			switch (vertexStructVersion)
			{
				case Mesh::VertexStructVersion::P:
				{
					vertexStructSize = sizeof(Mesh::PVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					break;
				}
				case Mesh::VertexStructVersion::PUV:
				{
					vertexStructSize = sizeof(Mesh::PUVVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					break;
				}
				case Mesh::VertexStructVersion::PN:
				{
					vertexStructSize = sizeof(Mesh::PNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f));
					break;
				}
				case Mesh::VertexStructVersion::PUVN:
				{
					vertexStructSize = sizeof(Mesh::PUVNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f));
					break;
				}
				case Mesh::VertexStructVersion::PUVNTB:
				{
					vertexStructSize = sizeof(Mesh::PUVNTBVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f));
					vertexBufferLayout.Push(3, "TANGENT", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f) + sizeof(Vector3f));
					vertexBufferLayout.Push(4, "BITANGENT", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f) + sizeof(Vector3f) + sizeof(Vector3f));
					break;
				}
				default:
					break;
			}

			vertexBuffer->Create(&(*(vector<Mesh::PUVNVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PUVNVertexData>*)vertices)->size() * vertexStructSize);
			GetVertexBuffer()->SetLayout(vertexBufferLayout);

			indexBuffer->Create(&indices[0], (unsigned int)indices.size());
		}

		void Mesh::Bind() const
		{
			material->Bind();
			vertexBuffer->Bind();
			indexBuffer->Bind();
		}

		void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
			vertexBuffer->Unbind();
			material->Unbind();
		}

		unsigned int Mesh::GetVerticesCount() const
		{
			switch (vertexStructVersion)
			{
				case Mesh::VertexStructVersion::P:
				{
					return (unsigned int)((vector<Mesh::PVertexData*>*)vertices)->size();
					break;
				}
				case Mesh::VertexStructVersion::PUV:
				{
					return (unsigned int)((vector<Mesh::PUVVertexData*>*)vertices)->size();
					break;
				}
				case Mesh::VertexStructVersion::PN:
				{
					return (unsigned int)((vector<Mesh::PNVertexData*>*)vertices)->size();
					break;
				}
				case Mesh::VertexStructVersion::PUVN:
				{
					return (unsigned int)((vector<Mesh::PUVNVertexData*>*)vertices)->size();
					break;
				}
				case Mesh::VertexStructVersion::PUVNTB:
				{
					return (unsigned int)((vector<Mesh::PUVNTBVertexData*>*)vertices)->size();
					break;
				}
				default:
				{
					return 0;
					break;
				}
			}
		}
	}
}