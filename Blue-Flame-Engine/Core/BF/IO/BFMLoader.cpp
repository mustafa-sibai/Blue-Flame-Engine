#include "BFMLoader.h"
#include "BF/IO/FileFormats/BFMFormat.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics;
		using namespace BF::IO::FileFormats;

		static Graphics::TileMapData* tileMapData;

		TileMapData* BFMLoader::Load(const string& filename)
		{
			char fileHeader[9];
			tileMapData = new TileMapData();
			BFMFormat bfmFormat;

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
			if (strcmp(fileHeader, "BFM FILE") != 0)
			{
				printf("Error: Wrong file format: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(&bfmFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfmFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			fread(&bfmFormat.textureStringCount, sizeof(unsigned int), 1, file);
			tileMapData->textures = vector<string>(bfmFormat.textureStringCount);

			for (size_t i = 0; i < bfmFormat.textureStringCount; i++)
			{
				fread(&bfmFormat.textureStringSize, sizeof(unsigned int), 1, file);

				tileMapData->textures[i] = string(bfmFormat.textureStringSize, '\0');
				fread(&tileMapData->textures[i][0], bfmFormat.textureStringSize, 1, file);
			}

			fread(&bfmFormat.tilesSize, sizeof(unsigned int), 1, file);
			tileMapData->tilesData = vector<TileData>(bfmFormat.tilesSize / sizeof(TileData));
			fread(&tileMapData->tilesData[0], bfmFormat.tilesSize, 1, file);

			fclose(file);
			return tileMapData;
		}
	}
}