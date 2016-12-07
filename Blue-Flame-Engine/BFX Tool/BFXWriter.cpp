#include "BFXWriter.h"

BFXWriter::BFXWriter(const std::vector<Mesh>* mesh)
{
	this->mesh = mesh;
}

BFXWriter::~BFXWriter()
{
}

void BFXWriter::WriteToFile(const std::string& filename)
{
	bfxFormat.fileHeader = "BFX FILE";
	bfxFormat.majorFileVersion = 0;
	bfxFormat.minorFileVersion = 1;
	bfxFormat.meshCount = (unsigned int)mesh->size();

	FILE* file;
	file = fopen((filename + ".bfx").c_str(), "wb");
	
	if (!file)
	{
		printf("Error: Could not create new file to write to.\n");
		fclose(file);
		return;
	}

	fwrite(bfxFormat.fileHeader,		sizeof(char) * 8,		1, file);
	fwrite(&bfxFormat.majorFileVersion, sizeof(uint8_t),		1, file);
	fwrite(&bfxFormat.minorFileVersion, sizeof(uint8_t),		1, file);
	fwrite(&bfxFormat.meshCount,		sizeof(unsigned int),	1, file);
	
	for (size_t i = 0; i < mesh->size(); i++)
	{
		bfxFormat.vertexBufferSize	= (unsigned int)(sizeof(MeshVertexData) * mesh[0][i].GetVertices()->size());
		bfxFormat.vertexBuffer		= (uint8_t*)&mesh[0][i].GetVertices()[0][0];
		bfxFormat.indexBufferSize	= (unsigned int)(sizeof(unsigned int) * mesh[0][i].GetIndices()->size());
		bfxFormat.indexBuffer		= (uint8_t*)&mesh[0][i].GetIndices()[0][0];
	
		fwrite(&bfxFormat.vertexBufferSize, sizeof(unsigned int),		1, file);
		fwrite(bfxFormat.vertexBuffer,		bfxFormat.vertexBufferSize, 1, file);
		fwrite(&bfxFormat.indexBufferSize,	sizeof(unsigned int),		1, file);
		fwrite(bfxFormat.indexBuffer,		bfxFormat.indexBufferSize,	1, file);
	}
	
	fclose(file);
}