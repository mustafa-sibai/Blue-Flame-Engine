#pragma once
#include <string>
#include "DependencyHeaders/FreeImage/FreeImage.h"
#include "DependencyHeaders/FreeImage/Utilities.h"
#include "BF/Graphics/API/TextureData.h"
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
			static BF::Graphics::API::TextureData* Load(const std::string& filename);
			static void Unload(BF::Graphics::API::TextureData* textureData);

			static void DeInitialise();
		};
	}
}