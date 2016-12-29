#pragma once
#include <cstdint>

namespace BF
{
	namespace IO
	{
		namespace FileFormats
		{
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
		}
	}
}