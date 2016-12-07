#pragma once
#include <stdint.h>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			class BF_API Texture
			{
				public:
					enum class Format { R8 = 8, R8G8 = 16, R8G8B8 = 24, R8G8B8A8 = 32 };
					enum class TextureWrap { Repeat, MirroredReapeat, ClampToEdge, ClampToBorder };

					//TODO: Add more texture filter types to control both D3D11 min and mag
					enum class TextureFilter { Neatest, Linear };

				protected:
					const uint8_t* buffer;
					unsigned int width, height;

					Format format;
					TextureWrap textureWrap;
					TextureFilter textureFilter;

					Texture();
					~Texture();

				public:
					inline unsigned int GetWidth() const { return width; }
					inline unsigned int GetHeight() const { return height; }
					inline const uint8_t* GetBuffer() const { return buffer; }
			};
		}
	}
}