#include "BFXWriter.h"

namespace Editor
{
	namespace IO
	{
		using namespace std;
		using namespace BF::Graphics;

		BFXWriter::BFXWriter(const vector<Mesh>& mesh) :
			mesh(mesh)
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
			bfxFormat.meshCount = (unsigned int)mesh.size();

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

			for (size_t i = 0; i < mesh.size(); i++)
			{
				bfxFormat.meshType = (int)mesh[i].vertexStructVersion;
				fwrite(&bfxFormat.meshType, sizeof(int), 1, file);

				switch (mesh[i].vertexStructVersion)
				{
					case Mesh::VertexStructVersion::P:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(Mesh::PVertexData) * mesh[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < mesh[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<Mesh::PVertexData*>*)mesh[i].GetVertices())[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(Mesh::PVertexData), 1, file);
						}
						break;
					}
					case Mesh::VertexStructVersion::PUV:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(Mesh::PUVVertexData) * mesh[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < mesh[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<Mesh::PUVVertexData*>*)mesh[i].GetVertices())[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(Mesh::PUVVertexData), 1, file);
						}
						break;
					}
					case Mesh::VertexStructVersion::PN:
					{
						int x = mesh[i].GetVerticesCount();

						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(Mesh::PNVertexData) * mesh[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < mesh[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<Mesh::PNVertexData*>*)mesh[i].GetVertices())[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(Mesh::PNVertexData), 1, file);
						}
						break;
					}
					case Mesh::VertexStructVersion::PUVN:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(Mesh::PUVNVertexData) * mesh[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < mesh[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<Mesh::PUVNVertexData*>*)mesh[i].GetVertices())[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(Mesh::PUVNVertexData), 1, file);
						}
						break;
					}
					case Mesh::VertexStructVersion::PUVNTB:
					{
						bfxFormat.vertexBufferSize = (unsigned int)(sizeof(Mesh::PUVNTBVertexData) * mesh[i].GetVerticesCount());
						fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int), 1, file);

						for (size_t j = 0; j < mesh[i].GetVerticesCount(); j++)
						{
							bfxFormat.vertexBuffer = (uint8_t*)(*(vector<Mesh::PUVNTBVertexData*>*)mesh[i].GetVertices())[j];
							fwrite(bfxFormat.vertexBuffer, sizeof(Mesh::PUVNTBVertexData), 1, file);
						}
						break;
					}

					default:
						break;
				}

				bfxFormat.indexBufferSize = (unsigned int)(sizeof(unsigned int) * mesh[i].GetIndices()->size());
				fwrite(&bfxFormat.indexBufferSize, sizeof(unsigned int), 1, file);

				bfxFormat.indexBuffer = (uint8_t*)&(*mesh[i].GetIndices())[0];
				fwrite(bfxFormat.indexBuffer, bfxFormat.indexBufferSize, 1, file);
			}

			fclose(file);
		}
	}
}