#pragma once
#include <string>
#include "BF/Graphics/TileMap.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API BFMLoader
		{
			public:
				static BF::Graphics::TileMapData* Load(const std::string& filename);
		};
	}
}