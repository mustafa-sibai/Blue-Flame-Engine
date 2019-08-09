#include "TextureAtlas.h"

namespace BF
{
	namespace Graphics
	{
		using namespace BF::Graphics::API;

		TextureAtlas::TextureAtlas()
		{
		}

		TextureAtlas::~TextureAtlas()
		{
		}

		void TextureAtlas::Create(int width, int height, Format format)
		{
			this->format = format;

			if (textureData == nullptr)
				textureData = new TextureData();

			textureData->width = width;
			textureData->height = height;
			textureData->bitsPerPixel = (int)format;
			textureData->size = textureData->width * textureData->height * (textureData->bitsPerPixel / 8);

			textureData->buffer = new uint8_t[textureData->size];
			memset(textureData->buffer, 0, sizeof(uint8_t) * textureData->size);
		}

		void TextureAtlas::AddTexture(const Math::Rectangle& rectangle, uint8_t* data)
		{
			//TODO: Count the bit depth. Right now I'm assuming the bit depth is 1.
			for (int row = rectangle.y; row < rectangle.y + rectangle.height; row++)
			{
				for (int col = rectangle.x; col < rectangle.x + rectangle.width; col++)
				{
					textureData->buffer[col + (row * textureData->width)] = data[(col - rectangle.x) + ((row - rectangle.y) * rectangle.width)];
				}
			}
		}
	}
}