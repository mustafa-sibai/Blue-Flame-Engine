#pragma once
#include <cstdint>

namespace BF
{
	namespace IO
	{
		namespace FileFormats
		{
			//Blue Flame Animation Format
			struct BFAFormat
			{
				char* fileHeader;
				uint8_t majorFileVersion;
				uint8_t minorFileVersion;

				unsigned int textureStringSize;
				uint8_t* textureString;

				unsigned int sequenceSize;

				unsigned int keyFrameSize;
				uint8_t* keyFrames;
			};
		}
	}
}