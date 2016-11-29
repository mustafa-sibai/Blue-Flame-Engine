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
				uint8_t* buffer;
				unsigned int bufferSize;

			public:
				TextureAtlas();
				~TextureAtlas();

				void Create(unsigned int width, unsigned int height, Format format);
				void AddTexture(const Math::Rectangle& rectangle, uint8_t* data);

				inline unsigned int GetWidth() const { return width; }
				inline unsigned int GetHeight() const { return height; }
				inline const uint8_t* GetBuffer() const { return buffer; }
		};
	}
}