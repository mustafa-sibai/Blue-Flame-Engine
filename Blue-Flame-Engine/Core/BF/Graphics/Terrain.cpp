#include "Terrain.h"
#include "BF/Engine.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Math/Math.h"
#include "BF/IO/ImageLoader.h"
#include "BF/System/Debug.h"

#define TERRAIN_WIDTH		256
#define TERRAIN_HEIGHT		256
#define QUAD_INDICES		6

#define ROW_VERTICES		(TERRAIN_WIDTH  + 1)
#define COLUMN_VERTICES		(TERRAIN_HEIGHT + 1)

#define VERTICES_SIZE		ROW_VERTICES * COLUMN_VERTICES
#define INDICES_SIZE		TERRAIN_WIDTH * TERRAIN_HEIGHT * QUAD_INDICES

#define TERRAIN_SCALE		30

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Math;
		using namespace BF::Graphics::API;

		Terrain::Terrain()
		{
		}

		Terrain::~Terrain()
		{
		}

		void Terrain::Initialize()
		{
			glEnable(GL_CULL_FACE);
			glFrontFace(GL_CW);
			glCullFace(GL_BACK);

			shader.LoadStandardShader(ShaderType::Terrain);

			vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, sizeof(Mesh::PUVNVertexData), 0);
			vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, sizeof(Mesh::PUVNVertexData), sizeof(Vector3f));
			vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, sizeof(Mesh::PUVNVertexData), sizeof(Vector3f) + sizeof(Vector2f));
		}

		void Terrain::Load(const std::string& filename)
		{
			textureData = BF::IO::ImageLoader::Load(filename);

			Mesh::PUVNVertexData* vertices = new Mesh::PUVNVertexData[VERTICES_SIZE];

			Vector3f startingPosition;
			Vector2f size = Vector2f(2.0f, 2.0f);
			int stride = 32 / 8;
			unsigned int* indecies = new unsigned int[INDICES_SIZE];
			int index = 0;

			for (int z = 0; z < COLUMN_VERTICES; z++)
			{
				startingPosition.z = size.y * z;

				for (int x = 0; x < ROW_VERTICES; x++)
				{
					startingPosition.x = size.x * x;

					int pixel = (x * stride) + (z * (int)textureData->width * stride);
					int v = textureData->buffer[pixel];

					float normalizedData = Normalize(v, 0, 256);

					vertices[x + (z * ROW_VERTICES)] = Mesh::PUVNVertexData(Vector3f(startingPosition.x, startingPosition.y + (normalizedData * TERRAIN_SCALE), -startingPosition.z), Vector2f(), Vector3f(0.0f, 1.0f, 0.0f));

					if (x < TERRAIN_WIDTH && z < TERRAIN_HEIGHT)
					{
						indecies[index + 0] = x + 0 + (z * ROW_VERTICES);
						indecies[index + 1] = x + 1 + (z * ROW_VERTICES);
						indecies[index + 2] = x + 1 + ((z + 1) * ROW_VERTICES);

						indecies[index + 3] = x + 1 + ((z + 1) * ROW_VERTICES);
						indecies[index + 4] = x + 0 + ((z + 1) * ROW_VERTICES);
						indecies[index + 5] = x + 0 + (z * ROW_VERTICES);

						index += 6;
					}
				}
			}

			for (int z = 0; z < COLUMN_VERTICES - 1; z++)
			{
				for (int x = 0; x < ROW_VERTICES - 1; x++)
				{
					const Vector3f &v0 = vertices[x + (z * ROW_VERTICES)].position;
					const Vector3f &v1 = vertices[(x + 1) + (z * ROW_VERTICES)].position;
					const Vector3f &v2 = vertices[(x + 1) + ((z + 1) * ROW_VERTICES)].position;

					Vector3f N = ((v1 - v0).Cross(v2 - v0)).Normalize();

					vertices[x + (z * ROW_VERTICES)].normal = N;
				}
			}

			vertexBuffer.Create(vertices, (unsigned int)VERTICES_SIZE * sizeof(Mesh::PUVNVertexData));
			indexBuffer.Create(indecies, INDICES_SIZE);

			vertexBuffer.SetLayout(shader, &vertexBufferLayout);

			delete[] indecies;
		}

		void Terrain::Render()
		{
			shader.Bind();
			vertexBuffer.Bind();
			indexBuffer.Bind();
			Engine::GetContext().Draw(indexBuffer.GetIndicesCount());
			indexBuffer.Unbind();
			vertexBuffer.Unbind();
			shader.Unbind();
		}
	}
}