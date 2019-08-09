#include "BFFWriter.h"

namespace Editor
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics::Fonts;

		BFFWriter::BFFWriter()
		{
		}

		BFFWriter::~BFFWriter()
		{
		}

		void BFFWriter::WriteToFile(const string& filename, const Font& font)
		{
			bffFormat.fileHeader = (uint8_t*)"BFF FILE";
			bffFormat.majorFileVersion = 0;
			bffFormat.minorFileVersion = 1;

			FILE* file = fopen((filename + ".bff").c_str(), "wb");
			if (!file)
			{
				printf("Error: Could not create new file to write to.\n");
				fclose(file);
				return;
			}

			fwrite(bffFormat.fileHeader, sizeof(uint8_t) * 8, 1, file);
			fwrite(&bffFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fwrite(&bffFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			bffFormat.fontNameCount = font.fontName.size();
			bffFormat.fontName = (uint8_t*)&font.fontName[0];

			fwrite(&bffFormat.fontNameCount, sizeof(uint32_t), 1, file);
			fwrite(bffFormat.fontName, sizeof(uint8_t) * bffFormat.fontNameCount, 1, file);

			fwrite(&font.fontPixelSize, sizeof(uint32_t), 1, file);
			fwrite(&font.fontMaxYBearing, sizeof(float_t), 1, file);

			fwrite(&font.texture->GetTextureData()->width, sizeof(uint32_t), 1, file);
			fwrite(&font.texture->GetTextureData()->height, sizeof(uint32_t), 1, file);
			fwrite(&font.texture->GetTextureData()->bitsPerPixel, sizeof(uint32_t), 1, file);
			fwrite(font.texture->GetTextureData()->buffer, sizeof(uint8_t) * font.texture->GetTextureData()->size, 1, file);

			bffFormat.charactersSize = (unsigned int)(sizeof(Character) * font.characters->size());
			bffFormat.characters = (uint8_t*)&(*font.characters)[0];

			fwrite(&bffFormat.charactersSize, sizeof(uint32_t), 1, file);
			fwrite(bffFormat.characters, bffFormat.charactersSize, 1, file);

			fclose(file);
		}
	}
}