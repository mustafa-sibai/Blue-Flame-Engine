#pragma once
#include "BF/Graphics/API/Texture.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		class BF_API TextureAtlas : public API::Texture
		{
			private:
				unsigned int bufferSize;

			public:
				TextureAtlas();
				~TextureAtlas();

				void Create(unsigned int width, unsigned int height, Format format);
				void AddTexture(const Math::Rectangle& rectangle, uint8_t* data);
		};
	}
}