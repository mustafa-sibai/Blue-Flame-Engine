#include "TextureAtlas.h"

namespace BF
{
	namespace Graphics
	{
		TextureAtlas::TextureAtlas() : 
			bufferSize(0)
		{
		}

		TextureAtlas::~TextureAtlas()
		{
		}

		void TextureAtlas::Create(unsigned int width, unsigned int height, Format format)
		{
			this->width = width;
			this->height = height;
			this->format = format;

			bufferSize = width * height * ((unsigned int)format / 8);

			buffer = new uint8_t[bufferSize];
			memset(buffer, 0, sizeof(uint8_t) * bufferSize);
		}

		void TextureAtlas::AddTexture(const Math::Rectangle& rectangle, uint8_t* data)
		{
			//TODO: Count the bit depth. Right now I'm assuming the bit depth is 1.
			for (int row = rectangle.y; row < rectangle.y + rectangle.height; row++)
			{
				for (int col = rectangle.x; col < rectangle.x + rectangle.width; col++)
				{
					buffer[col + (row * width)] = data[(col - rectangle.x) + ((row - rectangle.y) * rectangle.width)];
				}
			}
		}
	}
}