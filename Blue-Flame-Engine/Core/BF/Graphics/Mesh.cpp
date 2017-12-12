#include "Mesh.h"

namespace BF
{
	namespace Graphics
	{
		using namespace std;
		using namespace BF::Math;
		using namespace BF::Graphics::API;

		Mesh::Mesh(void* vertices, vector<unsigned int>& indices, VertexStructVersion vertexStructVersion/*, vector<Material>* materials*/) :
			vertexBuffer(nullptr), indexBuffer(nullptr), /*textures(nullptr),*/ vertices(vertices), indices(indices), vertexStructVersion(vertexStructVersion)/*, materials(materials), texturefilename("")*/
		{
		}

		Mesh::~Mesh()
		{
		}

		void Mesh::SetBuffers(const Shader& shader, unsigned int bufferSize)
		{
			vertexBuffer = new VertexBuffer(shader);
			indexBuffer = new IndexBuffer();
			//textures = new std::vector<Texture2D*>();

			vertexBuffer->Create(&(*(vector<Mesh::PUVNVertexData>*)vertices)[0], (unsigned int)((vector<Mesh::PUVNVertexData>*)vertices)->size() * bufferSize);
			indexBuffer->Create(&indices[0], (unsigned int)indices.size());



			/*for (size_t i = 0; i < materials->size(); i++)
			{
				if (strcmp(materials[0][i].diffuseMapName.c_str(), "") != 0)
				{
					textures->push_back(new Texture2D(context, shader));
					textures[0][textures->size() - 1]->Load(materials[0][i].diffuseMapName.c_str());
				}
			}*/
		}

		void Mesh::SetTexturefilename(string textureFilename)
		{
			this->textureFilename = textureFilename;
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

		unsigned int Mesh::getVerticesCount() const
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