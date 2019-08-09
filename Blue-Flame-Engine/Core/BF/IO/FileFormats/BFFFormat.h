#pragma once
#include <cstdint>

namespace BF
{
	namespace IO
	{
		namespace FileFormats
		{
			//Blue Flame Font Format
			struct BFFFormat
			{
				uint8_t* fileHeader;
				uint8_t majorFileVersion;
				uint8_t minorFileVersion;

				uint32_t fontNameCount;
				uint8_t* fontName;

				uint32_t fontPixelSize;
				float_t fontMaxYBearing;

				uint32_t width;
				uint32_t height;
				uint32_t bitsPerPixel;
				uint8_t* buffer;

				uint32_t charactersSize;
				uint8_t* characters;
			};
		}
	}
}