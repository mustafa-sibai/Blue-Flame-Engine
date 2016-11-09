#pragma once
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API WAVLoader
		{
			private:
				struct WAVHeader;
				static WAVHeader wavHeader;

			public:
				static uint8_t* Load(const char* filename, uint32_t* size, uint32_t* sampleRate, uint16_t* bitsPerSample, uint16_t* numChannels);
		};
	}
}