#include "BFALoader.h"
#include "BF/IO/FileFormats/BFAFormat.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::IO::FileFormats;
		using namespace BF::Graphics::Animation;

		static AnimationData* spriteAnimationData;

		AnimationData* BFALoader::Load(const string& filename)
		{
			/*char fileHeader[9];
			BFAFormat bfaFormat;
			spriteAnimationData = new SpriteAnimationData();

			FILE* file;
			file = fopen(filename.c_str(), "rb");

			if (!file)
			{
				printf("Error: Could not find/open BFX filename: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(fileHeader, sizeof(char), 8, file);
			fileHeader[8] = '\0';
			if (strcmp(fileHeader, "BFA FILE") != 0)
			{
				printf("Error: Wrong file format: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(&bfaFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfaFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			fread(&bfaFormat.textureStringSize, sizeof(unsigned int), 1, file);

			spriteAnimationData->textureName = string(bfaFormat.textureStringSize / sizeof(char), '\0');
			fread(&spriteAnimationData->textureName[0], sizeof(char), bfaFormat.textureStringSize, file);

			fread(&bfaFormat.sequenceSize, sizeof(unsigned int), 1, file);
			unsigned int sequencesCount = bfaFormat.sequenceSize / sizeof(Sequence);
			spriteAnimationData->sequences = vector<Sequence>(sequencesCount);

			for (unsigned int i = 0; i < sequencesCount; i++)
			{
				fread(&bfaFormat.keyFrameSize, sizeof(unsigned int), 1, file);
				unsigned int keyFramesCount = bfaFormat.keyFrameSize / sizeof(KeyFrame);
				spriteAnimationData->sequences[i].keyFrames = vector<KeyFrame>(keyFramesCount);

				fread(&spriteAnimationData->sequences[i].keyFrames[0], bfaFormat.keyFrameSize, 1, file);
			}

			fclose(file);
			return spriteAnimationData;*/
			return nullptr;
		}
	}
}