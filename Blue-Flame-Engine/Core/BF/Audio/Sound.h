#pragma once
#include "DependencyHeaders/OpenAL-Soft/AL/al.h"
#include "DependencyHeaders/OpenAL-Soft/AL/alc.h"
#include "DependencyHeaders/OpenAL-Soft/AL/alext.h"
#include "BF/IO/WAVLoader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Audio
	{
		class BF_API Sound
		{
			private:
				uint32_t dataSize;
				uint32_t sampleRate;
				uint16_t bitsPerSample;
				uint16_t numChannels;
				uint8_t* data;

				ALuint source;
				ALuint buffer;

			public:
				Sound();
				~Sound();

				void Load(const std::string& filename);
				void Play(bool loop);

			private:
				ALenum getFormat(uint16_t numChannels, uint16_t bitsPerSample);
		};
	}
}