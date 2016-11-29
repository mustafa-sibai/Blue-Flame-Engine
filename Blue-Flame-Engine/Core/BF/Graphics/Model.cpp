#include "Model.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::IO;
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Model::Model(API::Context* context, API::Shader* shader) :
			context(context), shader(shader), vertexBufferLayout(nullptr)
		{
			vertexBufferLayout = new VertexBufferLayout();
		}

		Model::~Model()
		{
		}

		void Model::Load(const std::string& filename)
		{
			//meshes = fbxLoader.meshes;

			vertexBufferLayout->Push(0, "POSITION", DataType::Float3, sizeof(MeshVertexData), 0);
			vertexBufferLayout->Push(1, "COLOR",	DataType::Float4, sizeof(MeshVertexData), sizeof(Vector3));
			vertexBufferLayout->Push(2, "TEXCOORD", DataType::Float2, sizeof(MeshVertexData), sizeof(Vector3) + sizeof(Vector4));
			vertexBufferLayout->Push(3, "NORMAL",	DataType::Float3, sizeof(MeshVertexData), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2));
			vertexBufferLayout->Push(4, "TEXTUREID", DataType::Float, sizeof(MeshVertexData), sizeof(Vector3) + sizeof(Vector4) + sizeof(Vector2) + sizeof(Vector3));

			for (size_t i = 0; i < meshes->size(); i++)
			{
				meshes[0][i].SetBuffers(context, shader);
				meshes[0][i].GetVertexBuffer()->SetLayout(vertexBufferLayout);
			}
		}

		void Model::Draw()
		{
			for (size_t i = 0; i < meshes->size(); i++)
			{
				meshes[0][i].Bind();
				context->Draw(meshes[0][i].GetIndices()->size());
				meshes[0][i].Unbind();
			}
		}
	}
}