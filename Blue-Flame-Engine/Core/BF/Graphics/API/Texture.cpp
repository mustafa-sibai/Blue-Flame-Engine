#include "Texture.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Texture::Texture() :
				buffer(nullptr), width(0), height(0), format(Format::None), textureWrap(TextureWrap::Repeat), textureFilter(TextureFilter::Neatest)
			{
			}

			Texture::~Texture()
			{
				delete buffer;
			}
		}
	}
}