#include "BFFLoader.h"
#include <vector>
#include "BF/IO/FileFormats/BFFFormat.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::IO;
		using namespace BF::IO::FileFormats;
		using namespace BF::Graphics::API;
		using namespace BF::Graphics::Fonts;

		Font* BFFLoader::Load(const string& filename)
		{
			char fileHeader[9];
			Font* font = new Font("", 0, 0, nullptr, nullptr);
			font->filePath = filename;

			BFFFormat bffFormat;

			FILE* file = fopen(filename.c_str(), "rb");
			if (!file)
			{
				printf("Error: Could not find/open BFF filename: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(fileHeader, sizeof(uint8_t), 8, file);
			fileHeader[8] = '\0';
			if (strcmp(fileHeader, "BFF FILE") != 0)
			{
				printf("Error: Wrong file format: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(&bffFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bffFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			fread(&bffFormat.fontNameCount, sizeof(uint32_t), 1, file);

			font->fontName = string(bffFormat.fontNameCount, '\0');
			fread(&font->fontName[0], sizeof(uint8_t) * bffFormat.fontNameCount, 1, file);

			fread(&font->fontPixelSize, sizeof(uint32_t), 1, file);
			fread(&font->fontMaxYBearing, sizeof(float_t), 1, file);

			fread(&bffFormat.width, sizeof(uint32_t), 1, file);
			fread(&bffFormat.height, sizeof(uint32_t), 1, file);
			fread(&bffFormat.bitsPerPixel, sizeof(uint32_t), 1, file);

			font->texture = new Texture2D();
			TextureData* textureData = new TextureData(bffFormat.width, bffFormat.height, bffFormat.bitsPerPixel, nullptr);
			textureData->buffer = new uint8_t[textureData->size];
			fread(textureData->buffer, sizeof(uint8_t) * textureData->size, 1, file);
			font->texture->Create(textureData);

			fread(&bffFormat.charactersSize, sizeof(uint32_t), 1, file);
			font->characters = new vector<Character>(bffFormat.charactersSize / sizeof(Character));
			fread(&(*font->characters)[0], bffFormat.charactersSize, 1, file);

			fclose(file);
			return font;
		}
	}
}