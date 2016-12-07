#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "BF/Graphics/Mesh.h"

namespace BF
{
	namespace IO
	{
		class BFXLoader
		{
			private:
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
				} bfxFormat;

				//const std::vector<Mesh>* mesh;

			public:
				BFXLoader();
				~BFXLoader();

				std::vector<Graphics::Mesh>* Load(const std::string& filename);
		};
	}
}