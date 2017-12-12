#pragma once
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API FileLoader
		{
			public:
				static std::string LoadTextFile(const std::string& filename);
				static char* LoadBinaryFile(const std::string& filename, size_t* size);
		};
	}
}