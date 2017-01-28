#include "Texture.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Texture::Texture() :
				format(Format::R8G8B8A8), textureWrap(TextureWrap::Repeat), textureFilter(TextureFilter::Neatest)
			{
			}

			Texture::~Texture()
			{
			}
		}
	}
}