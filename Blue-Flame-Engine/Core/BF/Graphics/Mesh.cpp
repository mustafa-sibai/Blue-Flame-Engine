#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Mesh::Mesh(vector<MeshVertexData>* vertices, vector<unsigned int>* indices, std::string textureFileName) :
			vertexBuffer(nullptr), indexBuffer(nullptr), texture2D(nullptr), vertices(vertices), indices(indices), textureFileName(textureFileName)
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(API::Context* context, API::Shader* shader)
		{
			vertexBuffer = new VertexBuffer(context, shader);
			indexBuffer = new IndexBuffer(context);
			texture2D = new Texture2D(context);

			vertexBuffer->Create(&vertices[0][0], (unsigned int)vertices->size() * sizeof(MeshVertexData));
			indexBuffer->Create(&indices[0][0], (unsigned int)indices->size());

			texture2D->Load(textureFileName.c_str());
		}

		void Mesh::Bind() const
		{
			texture2D->Bind();
			vertexBuffer->Bind();
			indexBuffer->Bind();
		}

		void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
			vertexBuffer->Unbind();
			texture2D->Unbind();
		}
	}
}