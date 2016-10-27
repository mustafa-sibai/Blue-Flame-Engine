#pragma once
#include <chrono>
#include "BF/Common.h"

namespace BF
{
	namespace System
	{
		class BF_API Timer
		{
			private:
				std::chrono::time_point<std::chrono::steady_clock> start;

			public:
				Timer();
				~Timer();

				void Reset();

				double GetElapsedTimeInNanoseconds();
				double GetElapsedTimeInMilliseconds();
				double GetElapsedTimeInSeconds();
		};
	}
}