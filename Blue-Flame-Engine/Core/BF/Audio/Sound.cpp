#include "Sound.h"

namespace BF
{
	namespace Audio
	{
		using namespace BF::IO;

		Sound::Sound()
		{
		}

		Sound::~Sound()
		{
		}

		void Sound::Load(const char* filename)
		{
			data = WAVLoader::Load(filename, &dataSize, &sampleRate, &bitsPerSample, &numChannels);

			alGenSources(1, &source);
			alGenBuffers(1, &buffer);

			alBufferData(buffer, getFormat(numChannels, bitsPerSample), data, dataSize, sampleRate);
		}

		void Sound::Play(bool loop)
		{
			alSourcef(source, AL_PITCH, 1);
			alSourcef(source, AL_GAIN, 1);
			alSource3f(source, AL_POSITION, 0, 0, 0);
			alSource3f(source, AL_VELOCITY, 0, 0, 0);

			if (loop)
				alSourcei(source, AL_LOOPING, AL_TRUE);
			else
				alSourcei(source, AL_LOOPING, AL_FALSE);

			alSourcei(source, AL_BUFFER, buffer);
			alSourcePlay(source);
		}

		ALenum Sound::getFormat(uint16_t numChannels, uint16_t bitsPerSample)
		{
			bool stereo = (numChannels > 1);

			switch (bitsPerSample)
			{
				case 32:
				{
					if (stereo)
						return AL_FORMAT_STEREO_FLOAT32;
					else
						return AL_FORMAT_MONO_FLOAT32;
				}
				case 16:
				{
					if (stereo)
						return AL_FORMAT_STEREO16;
					else
						return AL_FORMAT_MONO16;
				}
				case 8:
				{
					if (stereo)
						return AL_FORMAT_STEREO8;
					else
						return AL_FORMAT_MONO8;
				}
				default:
					return -1;
			}
		}
	}
}