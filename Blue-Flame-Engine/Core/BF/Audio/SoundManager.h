#pragma once
#include "DependencyHeaders/OpenAL-Soft/AL/al.h"
#include "DependencyHeaders/OpenAL-Soft/AL/alc.h"
#include "DependencyHeaders/OpenAL-Soft/AL/alext.h"
#include <BF/Common.h>

namespace BF
{
	namespace Audio
	{
		class BF_API SoundManager
		{
			public:
				SoundManager();
				~SoundManager();
		};
	}
}