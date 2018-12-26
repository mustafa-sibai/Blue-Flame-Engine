#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Graphics::API;
		using namespace BF::Graphics::Materials;

		Mesh::Mesh(PresetMeshes presetMeshes) :
			vertexBuffer(nullptr), indexBuffer(nullptr), vertices(nullptr), indices(nullptr), vertexStructVersion(Mesh::VertexStructVersion::P)
		{
			Component::type = Component::Type::Mesh;

			if (presetMeshes == PresetMeshes::Plane)
			{
				vertices = new vector<Mesh::PVertexData>(4);
				indices = new std::vector<unsigned int>(6);

				(*indices)[0] = 0;
				(*indices)[1] = 1;
				(*indices)[2] = 2;

				(*indices)[3] = 2;
				(*indices)[4] = 3;
				(*indices)[5] = 0;

				Vector3f position(0.0f, 0.0f, 0.0f);
				Vector3f size(1.0f, 1.0f, 1.0f);

				//Top Left
				(*(vector<Mesh::PVertexData>*)vertices)[0] = Mesh::PVertexData(position);

				//Top Right
				(*(vector<Mesh::PVertexData>*)vertices)[1] = Mesh::PVertexData(Vector3f(position.x + size.x, position.y, position.z));

				//Bottom Right
				(*(vector<Mesh::PVertexData>*)vertices)[2] = Mesh::PVertexData(Vector3f(position.x + size.x, position.y, position.z + size.z));

				//Bottom Left
				(*(vector<Mesh::PVertexData>*)vertices)[3] = Mesh::PVertexData(Vector3f(position.x, position.y, position.z + size.z));


				/*//Top Left
				(*(vector<Mesh::PUVVertexData>*)vertices)[0] = Mesh::PUVVertexData(position, Vector2f(0.0f, 0.0f));

				//Top Right
				(*(vector<Mesh::PUVVertexData>*)vertices)[1] = Mesh::PUVVertexData(Vector3f(position.x + size.x, position.y, position.z), Vector2f(1.0f, 0.0f));

				//Bottom Right
				(*(vector<Mesh::PUVVertexData>*)vertices)[2] = Mesh::PUVVertexData(Vector3f(position.x + size.x, position.y + size.y, position.z), Vector2f(1.0f, 1.0f));

				//Bottom Left
				(*(vector<Mesh::PUVVertexData>*)vertices)[3] = Mesh::PUVVertexData(Vector3f(position.x, position.y + size.y, position.z), Vector2f(0.0f, 1.0f));*/
			}
		}

		Mesh::Mesh(void* vertices, vector<unsigned int>* indices, VertexStructVersion vertexStructVersion) :
			vertexBuffer(nullptr), indexBuffer(nullptr), vertices(vertices), indices(indices), vertexStructVersion(vertexStructVersion)
		{
			Component::type = Component::Type::Mesh;
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(MeshMaterial* material)
		{
			this->material = material;

			vertexBuffer = new VertexBuffer();
			indexBuffer = new IndexBuffer();

			unsigned int vertexStructSize = 0;

			switch (vertexStructVersion)
			{
				case Mesh::VertexStructVersion::P:
				{
					vertexStructSize = sizeof(Mesh::PVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);

					vertexBuffer->Create(&(*(vector<Mesh::PVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PVertexData>*)vertices)->size() * vertexStructSize);
					break;
				}
				case Mesh::VertexStructVersion::PUV:
				{
					vertexStructSize = sizeof(Mesh::PUVVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));

					vertexBuffer->Create(&(*(vector<Mesh::PUVVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PUVVertexData>*)vertices)->size() * vertexStructSize);
					break;
				}
				case Mesh::VertexStructVersion::PN:
				{
					vertexStructSize = sizeof(Mesh::PNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f));

					vertexBuffer->Create(&(*(vector<Mesh::PNVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PNVertexData>*)vertices)->size() * vertexStructSize);
					break;
				}
				case Mesh::VertexStructVersion::PUVN:
				{
					vertexStructSize = sizeof(Mesh::PUVNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f));

					vertexBuffer->Create(&(*(vector<Mesh::PUVNVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PUVNVertexData>*)vertices)->size() * vertexStructSize);
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

					vertexBuffer->Create(&(*(vector<Mesh::PUVNTBVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PUVNTBVertexData>*)vertices)->size() * vertexStructSize);
					break;
				}
				default:
					break;
			}

			indexBuffer->Create(&(*indices)[0], (unsigned int)indices->size());
			vertexBuffer->SetLayout(*material->shader, &vertexBufferLayout);
		}

		void Mesh::Bind() const
		{
			//material->Bind();
			vertexBuffer->Bind();
			indexBuffer->Bind();
		}

		void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
			vertexBuffer->Unbind();
			//material->Unbind();
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