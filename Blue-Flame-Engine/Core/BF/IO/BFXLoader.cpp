#include "BFXLoader.h"

namespace BF
{
	namespace IO
	{
		using namespace Graphics;

		BFXLoader::BFXLoader()
		{
		}

		BFXLoader::~BFXLoader()
		{
		}

		std::vector<Mesh>* BFXLoader::Load(const std::string& filename)
		{
			char fileHeader[8];
			BFXFormat bfxFormat;
			std::vector<Mesh>* model = new std::vector<Mesh>();

			FILE* file;
			file = fopen(filename.c_str(), "rb");

			if (!file)
			{
				printf("Error: Could not find/open BFX filename: %s\n", filename.c_str());
				fclose(file);
				return nullptr;
			}

			fread(fileHeader, sizeof(char), 8, file);
			fread(&bfxFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.minorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.meshCount, sizeof(unsigned int), 1, file);

			for (size_t i = 0; i < bfxFormat.meshCount; i++)
			{
				fread(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);
				std::vector<MeshVertexData>* verticess = new std::vector<MeshVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshVertexData));
				fread(&verticess[0][0], bfxFormat.vertexBufferSize, 1, file);

				fread(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);
				std::vector<unsigned int>* indicess = new std::vector<unsigned int>(bfxFormat.indexBufferSize / sizeof(unsigned int));
				fread(&indicess[0][0], bfxFormat.indexBufferSize, 1, file);

				model->push_back(Mesh(verticess, indicess, nullptr));
			}

			fclose(file);

			return model;
		}
	}
}