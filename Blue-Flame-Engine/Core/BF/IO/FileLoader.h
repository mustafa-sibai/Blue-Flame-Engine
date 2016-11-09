#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API FileLoader
		{
			static std::string LoadTextFile(const char* fileName);
			static char* LoadBinaryFile(const char* fileName, size_t* size);
		};
	}
}