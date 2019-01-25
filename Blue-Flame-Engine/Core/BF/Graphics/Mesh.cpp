#include "Mesh.h"
#include "Materials/MaterialManager.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Graphics::API;
		using namespace BF::Graphics::Materials;

		Mesh::Mesh(PresetMeshes presetMeshes) :
			Component(Component::Type::Mesh),
			meshData(nullptr), vertexBuffer(nullptr), indexBuffer(nullptr)
		{
			if (presetMeshes == PresetMeshes::Plane)
			{
			}
		}

		Mesh::Mesh(MeshData* meshData) :
			Component(Component::Type::Mesh),
			meshData(meshData), vertexBuffer(nullptr), indexBuffer(nullptr)
		{
			SetBuffers(&MaterialManager::GetDefaultMaterial());
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

			switch (meshData->vertexStructVersion)
			{
				case MeshData::VertexStructVersion::P:
				{
					vertexStructSize = sizeof(MeshData::PVertexData);
					vertexBufferLayout.Push(0, "MATERIALINDEX", VertexBufferLayout::DataType::Float, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(int));

					vertexBuffer->Create((unsigned int)((vector<MeshData::PVertexData>*)meshData->vertices)->size() * vertexStructSize, &(*(vector<MeshData::PVertexData>*)meshData->vertices)[0]);
					break;
				}
				case MeshData::VertexStructVersion::PUV:
				{
					vertexStructSize = sizeof(MeshData::PUVVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));

					vertexBuffer->Create((unsigned int)((vector<MeshData::PUVVertexData>*)meshData->vertices)->size() * vertexStructSize, &(*(vector<MeshData::PUVVertexData>*)meshData->vertices)[0]);
					break;
				}
				case MeshData::VertexStructVersion::PN:
				{
					vertexStructSize = sizeof(MeshData::PNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f));

					vertexBuffer->Create((unsigned int)((vector<MeshData::PNVertexData>*)meshData->vertices)->size() * vertexStructSize, &(*(vector<MeshData::PNVertexData>*)meshData->vertices)[0]);
					break;
				}
				case MeshData::VertexStructVersion::PUVN:
				{
					vertexStructSize = sizeof(MeshData::PUVNVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f));

					vertexBuffer->Create((unsigned int)((vector<MeshData::PUVNVertexData>*)meshData->vertices)->size() * vertexStructSize, &(*(vector<MeshData::PUVNVertexData>*)meshData->vertices)[0]);
					break;
				}
				case MeshData::VertexStructVersion::PUVNTB:
				{
					vertexStructSize = sizeof(MeshData::PUVNTBVertexData);
					vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);
					vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, vertexStructSize, sizeof(Vector3f));
					vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f));
					vertexBufferLayout.Push(3, "TANGENT", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f) + sizeof(Vector3f));
					vertexBufferLayout.Push(4, "BITANGENT", VertexBufferLayout::DataType::Float3, vertexStructSize, sizeof(Vector3f) + sizeof(Vector2f) + sizeof(Vector3f) + sizeof(Vector3f));

					vertexBuffer->Create((unsigned int)((vector<MeshData::PUVNTBVertexData>*)meshData->vertices)->size() * vertexStructSize, &(*(vector<MeshData::PUVNTBVertexData>*)meshData->vertices)[0]);
					break;
				}
				default:
					break;
			}

			indexBuffer->Create(&(*meshData->indices)[0], (unsigned int)meshData->indices->size());
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
	}
}