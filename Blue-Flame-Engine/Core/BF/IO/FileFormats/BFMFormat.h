#pragma once
#include <cstdint>

namespace BF
{
	namespace IO
	{
		namespace FileFormats
		{
			struct BFMFormat
			{
				char* fileHeader;
				uint8_t majorFileVersion;
				uint8_t minorFileVersion;

				unsigned int textureStringCount;
				unsigned int textureStringSize;
				uint8_t* textureString;

				unsigned int tilesSize;
				uint8_t* tiles;
			};
		}
	}
}