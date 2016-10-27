#pragma once
#include <iostream>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API ImageReader
		{
			static uint8_t* ReadImage(const char* filename, unsigned int* width, unsigned int* height);
		};
	}
}