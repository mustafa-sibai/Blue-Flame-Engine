#include "BFAWriter.h"

namespace Editor
{
	namespace IO
	{
		BFAWriter::BFAWriter()
		{
		}

		BFAWriter::~BFAWriter()
		{
		}

		void BFAWriter::WriteToFile(const std::string& filename, const BF::Graphics::Animation::SpriteAnimationData& spriteAnimationData)
		{
			bfaFormat.fileHeader = "BFA FILE";
			bfaFormat.majorFileVersion = 0;
			bfaFormat.minorFileVersion = 1;

			FILE* file;
			file = fopen((filename + ".bfa").c_str(), "wb");
			if (!file)
			{
				printf("Error: Could not create new file to write to.\n");
				fclose(file);
				return;
			}

			fwrite(bfaFormat.fileHeader, sizeof(char) * 8, 1, file);
			fwrite(&bfaFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fwrite(&bfaFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			bfaFormat.textureStringSize = (unsigned int)(sizeof(char) * spriteAnimationData.textureName.size());
			bfaFormat.textureString = (uint8_t*)&spriteAnimationData.textureName[0];

			fwrite(&bfaFormat.textureStringSize, sizeof(unsigned int), 1, file);
			fwrite(bfaFormat.textureString, bfaFormat.textureStringSize, 1, file);

			bfaFormat.sequenceSize = (unsigned int)(sizeof(BF::Graphics::Animation::Sequence) * spriteAnimationData.sequences.size());
			fwrite(&bfaFormat.sequenceSize, sizeof(unsigned int), 1, file);

			for (unsigned int i = 0; i < spriteAnimationData.sequences.size(); i++)
			{
				bfaFormat.keyFrameSize = (unsigned int)(sizeof(BF::Graphics::Animation::KeyFrame) * spriteAnimationData.sequences[i].keyFrames.size());
				bfaFormat.keyFrames = (uint8_t*)&spriteAnimationData.sequences[i].keyFrames[0];

				fwrite(&bfaFormat.keyFrameSize, sizeof(unsigned int), 1, file);
				fwrite(bfaFormat.keyFrames, bfaFormat.keyFrameSize, 1, file);
			}

			fclose(file);
		}
	}
}