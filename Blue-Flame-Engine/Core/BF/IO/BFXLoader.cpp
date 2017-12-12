#include "BFXLoader.h"
#include "BF/System/Debug.h"

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
				BF_LOG_ERROR("Error: Could not find/open BFX filename: " + filename + "\n", "");
				fclose(file);
				return nullptr;
			}

			fread(fileHeader, sizeof(char), 8, file);
			fileHeader[8] = '\0';
			if (strcmp(fileHeader, "BFX FILE") != 0)
			{
				BF_LOG_ERROR("Error: Wrong file format: " + filename + "\n", "");
				fclose(file);
				return nullptr;
			}

			fread(&bfxFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.minorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.meshCount, sizeof(unsigned int), 1, file);

			for (size_t i = 0; i < bfxFormat.meshCount; i++)
			{
				fread(&bfxFormat.meshType, sizeof(int), 1, file);
				fread(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

				void* vertices = nullptr;

				switch ((Mesh::VertexStructVersion)bfxFormat.meshType)
				{
					case Mesh::VertexStructVersion::P:
					{
						vertices = new vector<Mesh::PVertexData>(bfxFormat.vertexBufferSize / sizeof(Mesh::PVertexData));
						fread(&(*(vector<Mesh::PVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
						break;
					}
					case Mesh::VertexStructVersion::PUV:
					{
						vertices = new vector<Mesh::PUVVertexData>(bfxFormat.vertexBufferSize / sizeof(Mesh::PUVVertexData));
						fread(&(*(vector<Mesh::PUVVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
						break;
					}
					case Mesh::VertexStructVersion::PN:
					{
						vertices = new vector<Mesh::PNVertexData>(bfxFormat.vertexBufferSize / sizeof(Mesh::PNVertexData));
						fread(&(*(vector<Mesh::PNVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
						break;
					}
					case Mesh::VertexStructVersion::PUVN:
					{
						vertices = new vector<Mesh::PUVNVertexData>(bfxFormat.vertexBufferSize / sizeof(Mesh::PUVNVertexData));
						fread(&(*(vector<Mesh::PUVNVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
						break;
					}
					case Mesh::VertexStructVersion::PUVNTB:
					{
						vertices = new vector<Mesh::PUVNTBVertexData>(bfxFormat.vertexBufferSize / sizeof(Mesh::PUVNTBVertexData));
						fread(&(*(vector<Mesh::PUVNTBVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
						break;
					}
					default:
						break;
				}

				fread(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);
				vector<unsigned int>* indices = new vector<unsigned int>(bfxFormat.indexBufferSize / sizeof(unsigned int));
				fread(&(*indices)[0], bfxFormat.indexBufferSize, 1, file);

				model->push_back(Mesh(vertices, *indices, (Mesh::VertexStructVersion)bfxFormat.meshType));
			}

			fclose(file);
			return model;
		}
	}
}