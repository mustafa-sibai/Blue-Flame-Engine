#pragma once
#include <string>
#include "DependencyHeaders/FreeImage/FreeImage.h"
#include "DependencyHeaders/FreeImage/Utilities.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API ImageLoader
		{
			private:
				static bool initialised;

			public:
				static BF::Graphics::API::Texture::TextureData* Load(const std::string& filename);
				static void Unload(BF::Graphics::API::Texture::TextureData* textureData);

				static void DeInitialise();
		};
	}
}