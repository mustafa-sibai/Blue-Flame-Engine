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
			meshData(nullptr), vertexBuffer(nullptr), indexBuffer(nullptr), materialManager(nullptr)
		{
			if (presetMeshes == PresetMeshes::Plane)
			{
			}
		}

		Mesh::Mesh(MeshData* meshData) :
			meshData(meshData), vertexBuffer(nullptr), indexBuffer(nullptr), materialManager(nullptr)
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::Initialize(MaterialManager* materialManager)
		{
			this->materialManager = materialManager;
			SetMeshData(meshData);
			vertexBuffer->SetLayout(*MaterialManager::GetDefaultMaterial().shader, &vertexBufferLayout);
		}

		void Mesh::SetMeshData(MeshData* meshData)
		{
			vertexBuffer = new VertexBuffer();
			indexBuffer = new IndexBuffer();

			unsigned int vertexStructSize = 0;

			switch (meshData->vertexStructVersion)
			{
			case MeshData::VertexStructVersion::P:
			{
				vertexStructSize = sizeof(MeshData::PVertexData);
				vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, vertexStructSize, 0);

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