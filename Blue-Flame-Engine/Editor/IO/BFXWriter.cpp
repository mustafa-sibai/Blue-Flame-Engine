#include "BFXWriter.h"

namespace Editor
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics;

		BFXWriter::BFXWriter(const vector<MeshData>& meshesData) :
			meshesData(meshesData)
		{
		}

		BFXWriter::~BFXWriter()
		{
		}

		void BFXWriter::WriteToFile(const string& filename)
		{
			bfxFormat.fileHeader = "BFX FILE";
			bfxFormat.majorFileVersion = 0;
			bfxFormat.minorFileVersion = 3;
			bfxFormat.meshCount = (unsigned int)meshesData.size();

			FILE* file;
			file = fopen((filename + ".bfx").c_str(), "wb");

			if (!file)
			{
				printf("Error: Could not create new file to write to.\n");
				fclose(file);
				return;
			}

			fwrite(bfxFormat.fileHeader, sizeof(char) * 8, 1, file);
			fwrite(&bfxFormat.majorFileVersion, sizeof(uint8_t), 1, file);
			fwrite(&bfxFormat.minorFileVersion, sizeof(uint8_t), 1, file);
			fwrite(&bfxFormat.meshCount, sizeof(unsigned int), 1, file);

			for (size_t i = 0; i < meshesData.size(); i++)
			{
				bfxFormat.meshType = (int)meshesData[i].vertexStructVersion;
				fwrite(&bfxFormat.meshType, sizeof(int), 1, file);

				switch (meshesData[i].vertexStructVersion)
				{
					case MeshData::VertexStructVersion::P:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(MeshData::PVertexData) * meshesData[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < meshesData[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<MeshData::PVertexData*>*)meshesData[i].vertices)[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(MeshData::PVertexData), 1, file);
						}
						break;
					}
					case MeshData::VertexStructVersion::PUV:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(MeshData::PUVVertexData) * meshesData[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < meshesData[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<MeshData::PUVVertexData*>*)meshesData[i].vertices)[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(MeshData::PUVVertexData), 1, file);
						}
						break;
					}
					case MeshData::VertexStructVersion::PN:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(MeshData::PNVertexData) * meshesData[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < meshesData[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<MeshData::PNVertexData*>*)meshesData[i].vertices)[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(MeshData::PNVertexData), 1, file);
						}
						break;
					}
					case MeshData::VertexStructVersion::PUVN:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(MeshData::PUVNVertexData) * meshesData[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < meshesData[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<MeshData::PUVNVertexData*>*)meshesData[i].vertices)[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(MeshData::PUVNVertexData), 1, file);
						}
						break;
					}
					case MeshData::VertexStructVersion::PUVNTB:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(MeshData::PUVNTBVertexData) * meshesData[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < meshesData[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<MeshData::PUVNTBVertexData*>*)meshesData[i].vertices)[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(MeshData::PUVNTBVertexData), 1, file);
						}
						break;
					}

					default:
						break;
				}

				bfxFormat.indexBufferSize = (unsigned int)(sizeof(unsigned int) * meshesData[i].indices->size());
				fwrite(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);

				bfxFormat.indexBuffer = (uint8_t*)&(*meshesData[i].indices)[0];
				fwrite(bfxFormat.indexBuffer, bfxFormat.indexBufferSize, 1, file);
			}

			fclose(file);
		}
	}
}