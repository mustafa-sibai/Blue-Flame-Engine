#include "SoundManager.h"

namespace BF
{
	namespace Audio
	{
		SoundManager::SoundManager()
		{
			ALCdevice *device;

			device = alcOpenDevice(NULL);
			if (!device)
			{
				//printf("ERROR DEVICE OPENAL !!");
			}

			ALCcontext *context;

			context = alcCreateContext(device, NULL);
			if (!alcMakeContextCurrent(context))
			{
				//printf("ERROR CONTEXT OPENAL !!");
			}

			//ALboolean enumeration;

			//std::cout << alGetString(AL_VERSION) << std::endl;
			//std::cout << alGetString(AL_RENDERER) << std::endl;
		}

		SoundManager::~SoundManager()
		{
		}


		/*
		ALuint source;


		alGenSources((ALuint)1, &source);
		// check for errors

		alSourcef(source, AL_PITCH, 1);
		// check for errors
		alSourcef(source, AL_GAIN, 1);
		// check for errors
		alSource3f(source, AL_POSITION, 0, 0, 0);
		// check for errors
		alSource3f(source, AL_VELOCITY, 0, 0, 0);
		// check for errors
		alSourcei(source, AL_LOOPING, AL_FALSE);
		// check for errros

		ALuint buffer;

		alGenBuffers((ALuint)1, &buffer);
		// check for errors

		if (alIsExtensionPresent("AL_FORMAT_STEREO_FLOAT32"))
		{
		std::cout << "FLOAT OK\n";
		}
		else

		{
		std::cout << "FLOAT NO\n";
		}

		alBufferData(buffer, AL_FORMAT_STEREO_FLOAT32, wavHeader.data, wavHeader.dataSubChunkSize, wavHeader.sampleRate);

		ALenum err = alGetError();
		if (err != AL_NO_ERROR)
		{
		std::cout << err << std::endl;
		}

		alSourcei(source, AL_BUFFER, buffer);
		alSourcePlay(source);
		}*/
	}
}