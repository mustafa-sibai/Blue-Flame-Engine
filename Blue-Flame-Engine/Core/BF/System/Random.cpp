#include "Random.h"
#include <stdlib.h>
#include <time.h>

namespace BF
{
	namespace System
	{
		Random::Random()
		{
			srand(time(NULL));
		}

		Random::~Random()
		{
		}

		int Random::Range(int min, int max)
		{
			if (min < 0)
				max -= min;

			max++;

			return rand() % max + (min);
		}
	}
}