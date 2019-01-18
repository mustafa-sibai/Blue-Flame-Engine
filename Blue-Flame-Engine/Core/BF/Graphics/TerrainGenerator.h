#pragma once
#include "BF/Graphics/API/Shader.h"
#include "BF/Graphics/API/VertexBuffer.h"
#include "BF/Graphics/API/IndexBuffer.h"
#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API TerrainGenerator
		{
			private:
				BF::Graphics::API::Shader shader;
				BF::Graphics::API::VertexBuffer vertexBuffer;
				BF::Graphics::API::IndexBuffer indexBuffer;
				BF::Graphics::API::VertexBufferLayout vertexBufferLayout;

				BF::Graphics::API::Texture::TextureData* textureData;

			public:
				TerrainGenerator();
				~TerrainGenerator();

				void Initialize();
				void Load(const std::string& filename);
		};
	}
}