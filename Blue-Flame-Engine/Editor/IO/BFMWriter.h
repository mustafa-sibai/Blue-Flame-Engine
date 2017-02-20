#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <BF/Graphics/TileMap.h>
#include <BF/IO/FileFormats/BFMFormat.h>

namespace Editor
{
	namespace IO
	{
		class BFMWriter
		{
			private:
				BF::IO::FileFormats::BFMFormat bfmFormat;

			public:
				BFMWriter();
				~BFMWriter();

				void WriteToFile(const std::string& filename, const BF::Graphics::TileMapData& tileMapData);
		};
	}
}