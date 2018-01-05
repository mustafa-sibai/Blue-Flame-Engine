#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BF_API Random
		{
			public:
				Random();
				~Random();

				int Range(int min, int max);
		};
	}
}