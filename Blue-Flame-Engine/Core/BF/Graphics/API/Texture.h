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
					struct TextureData
					{
						unsigned int width;
						unsigned int height;
						uint8_t* buffer;

						TextureData() : width(0), height(0), buffer(nullptr) {};
						TextureData(unsigned int width, unsigned int height, uint8_t* buffer) :
							width(width), height(height), buffer(buffer)
						{
						}
					};

					enum class Format { R8 = 8, R8G8 = 16, R8G8B8 = 24, R8G8B8A8 = 32 };
					enum class TextureWrap { Repeat, MirroredReapeat, ClampToEdge, ClampToBorder };

					//TODO: Add more texture filter types to control both D3D11 min and mag
					enum class TextureFilter { Neatest, Linear };

				protected:
					TextureData textureData;
					Format format;
					TextureWrap textureWrap;
					TextureFilter textureFilter;

					Texture();
					~Texture();

				public:
					inline const TextureData& GetTextureData() const { return textureData; }
			};
		}
	}
}