#include "BFXLoader.h"
#include "FileFormats/BFXFormat.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics;
		using namespace BF::IO::FileFormats;

		static std::vector<Graphics::Mesh>* model;

		vector<Mesh>* BFXLoader::Load(const string& filename)
		{
			char fileHeader[9];
			model = new vector<Mesh>();
			BFXFormat bfxFormat;

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
			if (strcmp(fileHeader, "BFX FILE") != 0)
			{
				printf("Error: Wrong file format: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(&bfxFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.minorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.meshCount, sizeof(unsigned int), 1, file);

			for (size_t i = 0; i < bfxFormat.meshCount; i++)
			{
				fread(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);
				vector<MeshVertexData>* verticess = new vector<MeshVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshVertexData));
				fread(&verticess[0][0], bfxFormat.vertexBufferSize, 1, file);

				fread(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);
				vector<unsigned int>* indicess = new vector<unsigned int>(bfxFormat.indexBufferSize / sizeof(unsigned int));
				fread(&indicess[0][0], bfxFormat.indexBufferSize, 1, file);

				model->push_back(Mesh(verticess, indicess));
			}

			fclose(file);
			return model;
		}
	}
}