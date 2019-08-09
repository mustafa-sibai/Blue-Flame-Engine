#pragma once
#include <string>
#include "BF/Graphics/Fonts/Font.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API BFFLoader
		{
		public:
			static BF::Graphics::Fonts::Font* Load(const std::string& filename);
		};
	}
}