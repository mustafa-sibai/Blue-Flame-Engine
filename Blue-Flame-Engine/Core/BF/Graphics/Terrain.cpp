#include "Terrain.h"
#include "BF/Engine.h"
#include "BF/Graphics/Mesh.h"
#include "BF/Math/Math.h"
#include "BF/IO/ImageLoader.h"
#include "BF/System/Log.h"

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
		using namespace BF::Graphics::API;
		using namespace BF::Math;

		Terrain::Terrain() :
			vertexBuffer(shader)
		{
		}

		Terrain::~Terrain()
		{
		}

		void Terrain::Initialize()
		{
#if BF_PLATFORM_WINDOWS
			if (Context::GetRenderAPI() == RenderAPI::DirectX)
			{
				shader.LoadFromFile("../Sandbox/Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "../Sandbox/Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
			}
			else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			{
				shader.LoadFromFile("../Sandbox/Assets/Shaders/GLSL/3D/VertexShader.glsl", "../Sandbox/Assets/Shaders/GLSL/3D/PixelShader.glsl");
			}
#elif defined(BF_PLATFORM_LINUX)
			if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			{
				shader.LoadFromFile("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
			}
#endif

			vertexBufferLayout.Push(0, "POSITION", VertexBufferLayout::DataType::Float3, sizeof(MeshVertexData), 0);
			vertexBufferLayout.Push(1, "TEXCOORD", VertexBufferLayout::DataType::Float2, sizeof(MeshVertexData), sizeof(Vector3));
			vertexBufferLayout.Push(2, "NORMAL", VertexBufferLayout::DataType::Float3, sizeof(MeshVertexData), sizeof(Vector3) + sizeof(Vector2));
		}

		void Terrain::Load(const std::string& filename)
		{
			data = BF::IO::ImageLoader::Load(filename, &width, &height);

			MeshVertexData* vertices = new MeshVertexData[VERTICES_SIZE];

			Vector3 startingPosition;
			Vector2 size = Vector2(2.0f, 2.0f);
			int stride = 32 / 8;
			unsigned int* indecies = new unsigned int[INDICES_SIZE];
			int index = 0;

			for (unsigned int z = 0; z < COLUMN_VERTICES; z++)
			{
				startingPosition.z = size.y * z;

				for (unsigned int x = 0; x < ROW_VERTICES; x++)
				{
					startingPosition.x = size.x * x;

					float normalizedData = Normalize(data[((x * stride) + (z * width * stride))], 0, 256);

					vertices[x + (z * ROW_VERTICES)] = MeshVertexData(Vector3(startingPosition.x, startingPosition.y + (normalizedData * TERRAIN_SCALE), startingPosition.z),
						Vector2(), Vector3(0.0f, 1.0f, 0.0f));

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

			vertexBuffer.Create(vertices, (unsigned int)VERTICES_SIZE * sizeof(MeshVertexData));
			indexBuffer.Create(indecies, INDICES_SIZE);

			vertexBuffer.SetLayout(vertexBufferLayout);

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