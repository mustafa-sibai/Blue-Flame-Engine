#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API FileReader
		{
			static std::string ReadTextFile(const char* fileName);
			static char* ReadBinaryFile(const char* fileName, size_t* size);
		};
	}
}