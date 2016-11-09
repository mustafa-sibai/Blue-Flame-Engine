#include "WAVLoader.h"

namespace BF
{
	namespace IO
	{
		struct WAVLoader::WAVHeader
		{
			//RIFF Chunk
			char RIFFChunkID[4];
			uint32_t RIFFChunkSize;
			char format[4];

			//FMT SubChunk
			char FMTSubChunkID[4];
			uint32_t FMTSubChunkSize;
			uint16_t audioFormat;
			uint16_t numChannels;
			uint32_t sampleRate;
			uint32_t byteRate;
			uint16_t blockAlign;
			uint16_t bitsPerSample;

			//Data SubChunk
			char dataSubChunkID[4];
			uint32_t dataSubChunkSize;
			unsigned char* data;
		} WAVLoader::wavHeader;

		uint8_t* WAVLoader::Load(const char* filename, uint32_t* size, uint32_t* sampleRate, uint16_t* bitsPerSample, uint16_t* numChannels)
		{
			FILE* file = fopen(filename, "rb");

			if (!file)
			{
				fclose(file);
				printf("Error: Could not find/open WAV file.\n");
				return nullptr;
			}

			memset(&wavHeader, 0, sizeof(WAVHeader));

			fread(wavHeader.RIFFChunkID, sizeof(char), 4, file);
			if (strcmp(wavHeader.RIFFChunkID, "RIFF"))
			{
				fclose(file);
				printf("Error: Could not read RIFF chunk.\n");
				return nullptr;
			}

			fread(&wavHeader.RIFFChunkSize, sizeof(uint32_t), 1, file);

			fread(wavHeader.format, sizeof(char), 4, file);
			if (strcmp(wavHeader.format, "WAVE"))
			{
				fclose(file);
				printf("Error: Could not read WAVE format in RIFF chunk.\n");
				return nullptr;
			}

			fread(wavHeader.FMTSubChunkID, sizeof(char), 4, file);
			if (strcmp(wavHeader.FMTSubChunkID, "fmt "))
			{
				fclose(file);
				printf("Error: Could not read fmt chunk.\n");
				return nullptr;
			}

			fread(&wavHeader.FMTSubChunkSize, sizeof(uint32_t), 1, file);
			fread(&wavHeader.audioFormat, sizeof(uint16_t), 1, file);

			if (wavHeader.audioFormat != 1 && wavHeader.audioFormat != 3)
			{
				fclose(file);
				printf("Error: Audio is not PCM or IEEE float. Cannot read compressed audio format.\n");
				return nullptr;
			}

			fread(&wavHeader.numChannels,	sizeof(uint16_t), 1, file);
			fread(&wavHeader.sampleRate,	sizeof(uint32_t), 1, file);
			fread(&wavHeader.byteRate,		sizeof(uint32_t), 1, file);
			fread(&wavHeader.blockAlign,	sizeof(uint16_t), 1, file);
			fread(&wavHeader.bitsPerSample, sizeof(uint16_t), 1, file);

			if (wavHeader.FMTSubChunkSize > 16)
				fread(0, wavHeader.FMTSubChunkSize - 16, 1, file); //ignore extra parameters

			//Ignore all extra sub chunks until we get to the data chunk.
			while (true)
			{
				size_t result = fread(wavHeader.dataSubChunkID, sizeof(char), 4, file);
				fread(&wavHeader.dataSubChunkSize, sizeof(uint32_t), 1, file);

				if (strcmp(wavHeader.dataSubChunkID, "data"))
				{
					fseek(file, wavHeader.dataSubChunkSize, SEEK_CUR);

					if (result == 0)
					{
						fclose(file);
						printf("Error: Could not find data chunk.\n");
						return nullptr;
					}
				}
				else
				{
					wavHeader.data = new unsigned char[wavHeader.dataSubChunkSize];
					fread(wavHeader.data, wavHeader.dataSubChunkSize, 1, file);
					fclose(file);
					*size = wavHeader.dataSubChunkSize;
					*sampleRate = wavHeader.sampleRate;
					*bitsPerSample = wavHeader.bitsPerSample;
					*numChannels = wavHeader.numChannels;
					return wavHeader.data;
				}
			}
		}
	}
}