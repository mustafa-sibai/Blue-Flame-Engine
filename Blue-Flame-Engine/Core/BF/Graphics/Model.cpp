#include "Model.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Graphics
	{
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

		void Model::Load(const std::string& filename)
		{
			model = BFXLoader::Load(filename);

			vertexBufferLayout.Push(0, "POSITION",	VertexBufferLayout::DataType::Float3, sizeof(MeshVertexData), 0);
			//vertexBufferLayout->Push(1, "COLOR",	DataType::Float4, sizeof(MeshVertexData), sizeof(Vector3));
			vertexBufferLayout.Push(2, "TEXCOORD",	VertexBufferLayout::DataType::Float2, sizeof(MeshVertexData), sizeof(Vector3)/* + sizeof(Vector4)*/);
			vertexBufferLayout.Push(3, "NORMAL",	VertexBufferLayout::DataType::Float3, sizeof(MeshVertexData), sizeof(Vector3) /*+ sizeof(Vector4) */+ sizeof(Vector2));
			//vertexBufferLayout->Push(4, "TEXTUREID", DataType::Float, sizeof(MeshVertexData), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2) + sizeof(Vector3));

			for (size_t i = 0; i < model->size(); i++)
			{
				model[0][i].SetBuffers(shader);
				model[0][i].GetVertexBuffer()->SetLayout(vertexBufferLayout);
			}
		}

		void Model::Draw()
		{
			for (size_t i = 0; i < model->size(); i++)
			{
				model[0][i].Bind();
				Engine::GetContext().Draw((unsigned int)model[0][i].GetIndices()->size());
				model[0][i].Unbind();
			}
		}
	}
}