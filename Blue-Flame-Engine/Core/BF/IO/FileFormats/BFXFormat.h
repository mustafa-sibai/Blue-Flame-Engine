#pragma once
#include <cstdint>

namespace BF
{
	namespace IO
	{
		namespace FileFormats
		{
			//Blue Flame 3D Model Format
			struct BFXFormat
			{
				char* fileHeader;
				uint8_t majorFileVersion;
				uint8_t minorFileVersion;

				unsigned int meshCount;

				int meshType;

				unsigned int vertexBufferSize;
				uint8_t* vertexBuffer;

				unsigned int indexBufferSize;
				uint8_t* indexBuffer;
			};
		}
	}
}