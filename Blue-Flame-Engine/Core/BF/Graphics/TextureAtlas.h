#pragma once
#include "BF/Graphics/API/Texture.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BFE_API TextureAtlas : public BF::Graphics::API::Texture
		{
		public:
			TextureAtlas();
			~TextureAtlas();

			void Create(int width, int height, Format format);
			void AddTexture(const BF::Math::Rectangle& rectangle, uint8_t* data);
		};
	}
}