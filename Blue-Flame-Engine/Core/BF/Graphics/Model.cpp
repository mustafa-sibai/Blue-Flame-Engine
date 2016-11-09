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
			objReader = new OBJReader();
			vertexBufferLayout = new VertexBufferLayout();
		}

		Model::~Model()
		{
		}

		void Model::Load(const char* fileName)
		{
			meshes = objReader->Load(fileName);

			vertexBufferLayout->Push(0, "POSITION", DataType::Float3, sizeof(MeshVertexData), 0);
			//vertexBufferLayout->Push(1, "COLOR", DataType::Float4, sizeof(Vertex), 0);
			vertexBufferLayout->Push(2, "TEXCOORD", DataType::Float2, sizeof(MeshVertexData), sizeof(Vector3));

			for (size_t i = 0; i < meshes->size(); i++)
			{
				meshes[0][i].SetBuffers(context, shader);
				meshes[0][i].vertexBuffer->SetLayout(vertexBufferLayout);
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