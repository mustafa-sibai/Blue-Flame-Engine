#include "BFMWriter.h"

namespace Editor
{
	namespace IO
	{
		BFMWriter::BFMWriter()
		{
		}

		BFMWriter::~BFMWriter()
		{
		}

		void BFMWriter::WriteToFile(const std::string& filename, const BF::Graphics::TileMapData& tileMapData)
		{
			bfmFormat.fileHeader = "BFM FILE";
			bfmFormat.majorFileVersion = 0;
			bfmFormat.minorFileVersion = 1;

			FILE* file;
			file = fopen((filename + ".bfm").c_str(), "wb");

			if (!file)
			{
				printf("Error: Could not create new file to write to.\n");
				fclose(file);
				return;
			}

			fwrite(bfmFormat.fileHeader, sizeof(char) * 8, 1, file);
			fwrite(&bfmFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fwrite(&bfmFormat.minorFileVersion, sizeof(uint8_t), 1, file);

			bfmFormat.textureStringCount = (unsigned int)tileMapData.textures.size();
			fwrite(&bfmFormat.textureStringCount, sizeof(unsigned int), 1, file);

			for (size_t i = 0; i < bfmFormat.textureStringCount; i++)
			{
				bfmFormat.textureStringSize = (unsigned int)(sizeof(char) * tileMapData.textures[i].length());
				bfmFormat.textureString = (uint8_t*)&tileMapData.textures[i][0];

				fwrite(&bfmFormat.textureStringSize, sizeof(unsigned int), 1, file);
				fwrite(bfmFormat.textureString, bfmFormat.textureStringSize, 1, file);
			}

			bfmFormat.tilesSize = (unsigned int)(sizeof(BF::Graphics::TileData) * tileMapData.tilesData.size());
			bfmFormat.tiles = (uint8_t*)&tileMapData.tilesData[0];

			fwrite(&bfmFormat.tilesSize, sizeof(unsigned int), 1, file);
			fwrite(bfmFormat.tiles, bfmFormat.tilesSize, 1, file);

			fclose(file);
		}
	}
}