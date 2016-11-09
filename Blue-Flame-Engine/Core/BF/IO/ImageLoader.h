#pragma once
#include <iostream>
#include <FreeImage.h>
#include <Utilities.h>
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API ImageLoader
		{
			static uint8_t* Load(const char* filename, unsigned int* width, unsigned int* height);
		};
	}
}