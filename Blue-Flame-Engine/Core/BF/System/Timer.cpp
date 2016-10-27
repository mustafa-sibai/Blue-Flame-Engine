#include "Timer.h"

namespace BF
{
	namespace System
	{
		using namespace std;
		using namespace std::chrono;

		Timer::Timer()
		{
			Reset();
		}

		Timer::~Timer()
		{
		}

		void Timer::Reset()
		{
			start = steady_clock::now();
		}

		double Timer::GetElapsedTimeInNanoseconds()
		{
			return duration<double, nano>(steady_clock::now() - start).count();
		}

		double Timer::GetElapsedTimeInMilliseconds()
		{
			return duration<double, milli>(steady_clock::now() - start).count();
		}

		double Timer::GetElapsedTimeInSeconds()
		{
			return duration<double>(steady_clock::now() - start).count();
		}
	}
}