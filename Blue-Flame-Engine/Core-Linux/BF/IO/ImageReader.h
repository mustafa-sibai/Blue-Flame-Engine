#pragma once
#include <FreeImage.h>
#include <Utilities.h>
#include <iostream>
#include "../Common.h"

namespace BF
{
	namespace IO
	{
		struct BF_API ImageReader
		{
			static BYTE* ReadImage(const char *filename, unsigned int *width, unsigned int *height);
		};
	}
}