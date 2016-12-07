#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Mesh.h"

struct BFXFormat
{
	char* fileHeader;
	uint8_t majorFileVersion;
	uint8_t minorFileVersion;

	unsigned int meshCount;

	unsigned int vertexBufferSize;
	uint8_t* vertexBuffer;
	unsigned int indexBufferSize;
	uint8_t* indexBuffer;
};

class BFXWriter
{
private:
	BFXFormat bfxFormat;
	const std::vector<Mesh>* mesh;

public:
	BFXWriter(const std::vector<Mesh>* mesh);
	~BFXWriter();

	void WriteToFile(const std::string& filename);
};