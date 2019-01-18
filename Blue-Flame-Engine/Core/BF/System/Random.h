#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BFE_API Random
		{
			public:
				Random();
				~Random();

				int Range(int min, int max);
		};
	}
}