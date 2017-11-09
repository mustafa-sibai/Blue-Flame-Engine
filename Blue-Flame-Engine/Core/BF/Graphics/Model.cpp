#include "Model.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::IO;
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Model::Model(const Shader& shader) :
			shader(shader)
		{
		}

		Model::~Model()
		{
		}

		void Model::Load(const string& filename)
		{
			model = BFXLoader::Load(filename);

			unsigned int vertexStructSize = 0;

			switch ((*model)[0].vertexStructVersion)
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

			for (size_t i = 0; i < model->size(); i++)
			{
				(*model)[i].SetBuffers(shader, vertexStructSize);
				(*model)[i].GetVertexBuffer()->SetLayout(vertexBufferLayout);
			}
		}

		void Model::Render()
		{
			for (size_t i = 0; i < model->size(); i++)
			{
				(*model)[i].Bind();
				Engine::GetContext().Draw((unsigned int)(*model)[i].GetIndices().size());
				(*model)[i].Unbind();
			}
		}
	}
}