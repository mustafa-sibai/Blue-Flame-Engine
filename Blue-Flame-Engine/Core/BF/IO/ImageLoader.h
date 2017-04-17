#pragma once
#include <iostream>
#include "DependencyHeaders/FreeImage/FreeImage.h"
#include "DependencyHeaders/FreeImage/Utilities.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API ImageLoader
		{
			static uint8_t* Load(const std::string& filename, unsigned int* width, unsigned int* height);
		};
	}
}