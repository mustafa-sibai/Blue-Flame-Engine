#include "BFXLoader.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics;
		using namespace BF::IO::FileFormats;

		MeshData* BFXLoader::Load(const string& filename)
		{
			char fileHeader[9];
			BFXFormat bfxFormat;

			FILE* file;
			file = fopen(filename.c_str(), "rb");

			if (!file)
			{
				BFE_LOG_ERROR("Error: Could not find/open BFX filename: " + filename + "\n", "");
				fclose(file);
				return nullptr;
			}

			fread(fileHeader, sizeof(char), 8, file);
			fileHeader[8] = '\0';
			if (strcmp(fileHeader, "BFX FILE") != 0)
			{
				BFE_LOG_ERROR("Error: Wrong file format: " + filename + "\n", "");
				fclose(file);
				return nullptr;
			}

			fread(&bfxFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.minorFileVersion, sizeof(uint8_t), 1, file);
			fread(&bfxFormat.meshCount, sizeof(unsigned int), 1, file);

			void* vertices = nullptr;
			vector<unsigned int>* indices = nullptr;

			for (size_t i = 0; i < bfxFormat.meshCount; i++)
			{
				fread(&bfxFormat.meshType, sizeof(int), 1, file);
				fread(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

				switch ((MeshData::VertexStructVersion)bfxFormat.meshType)
				{
				case MeshData::VertexStructVersion::P:
				{
					vertices = new vector<MeshData::PVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshData::PVertexData));
					fread(&(*(vector<MeshData::PVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
					break;
				}
				case MeshData::VertexStructVersion::PUV:
				{
					vertices = new vector<MeshData::PUVVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshData::PUVVertexData));
					fread(&(*(vector<MeshData::PUVVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
					break;
				}
				case MeshData::VertexStructVersion::PN:
				{
					vertices = new vector<MeshData::PNVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshData::PNVertexData));
					fread(&(*(vector<MeshData::PNVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
					break;
				}
				case MeshData::VertexStructVersion::PUVN:
				{
					vertices = new vector<MeshData::PUVNVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshData::PUVNVertexData));
					fread(&(*(vector<MeshData::PUVNVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
					break;
				}
				case MeshData::VertexStructVersion::PUVNTB:
				{
					vertices = new vector<MeshData::PUVNTBVertexData>(bfxFormat.vertexBufferSize / sizeof(MeshData::PUVNTBVertexData));
					fread(&(*(vector<MeshData::PUVNTBVertexData>*)vertices)[0], bfxFormat.vertexBufferSize, 1, file);
					break;
				}
				default:
					break;
				}

				fread(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);
				indices = new vector<unsigned int>(bfxFormat.indexBufferSize / sizeof(unsigned int));
				fread(&(*(vector<unsigned int>*)indices)[0], bfxFormat.indexBufferSize, 1, file);
			}

			fclose(file);

			if (indices->size() > 0)
				return new MeshData(vertices, indices, (MeshData::VertexStructVersion)bfxFormat.meshType);
			else
			{
				BFE_LOG_ERROR("Error: failed to create mesh: " + filename + "\n", "");
				return nullptr;
			}
		}
	}
}