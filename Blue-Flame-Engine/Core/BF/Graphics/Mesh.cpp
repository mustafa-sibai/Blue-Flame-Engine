#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Mesh::Mesh(vector<MeshVertexData>* vertices, vector<unsigned int>* indices/*, vector<Material>* materials*/) :
			vertexBuffer(nullptr), indexBuffer(nullptr), /*textures(nullptr),*/ vertices(vertices), indices(indices)/*, materials(materials), textureFileName("")*/
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(const Shader& shader)
		{
			vertexBuffer = new VertexBuffer(shader);
			indexBuffer = new IndexBuffer();
			//textures = new std::vector<Texture2D*>();

			vertexBuffer->Create(&vertices[0][0], (unsigned int)vertices->size() * sizeof(MeshVertexData));
			indexBuffer->Create(&indices[0][0], (unsigned int)indices->size());

			/*for (size_t i = 0; i < materials->size(); i++)
			{
				if (strcmp(materials[0][i].diffuseMapName.c_str(), "") != 0)
				{
					textures->push_back(new Texture2D(context, shader));
					textures[0][textures->size() - 1]->Load(materials[0][i].diffuseMapName.c_str());
				}
			}*/
		}

		void Mesh::SetTextureFileName(string textureFileName)
		{
			this->textureFileName = textureFileName;
		}

		void Mesh::Bind() const
		{
			vertexBuffer->Bind();
			indexBuffer->Bind();
		}

		void Mesh::Unbind() const
		{
			indexBuffer->Unbind();
			vertexBuffer->Unbind();
			//for (size_t i = 0; i < textures->size(); i++)
				//textures[0][i]->Unbind();
		}
	}
}