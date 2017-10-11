#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API FileLoader
		{
			static std::string LoadTextFile(const std::string& filename);
			static char* LoadBinaryFile(const std::string& filename, size_t* size);
		};
	}
}