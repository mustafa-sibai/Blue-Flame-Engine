#pragma once
#include <string>
#include "BF/Graphics/Animation/AnimationData.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API BFALoader
		{
			public:
				static BF::Graphics::Animation::AnimationData* Load(const std::string& filename);
		};
	}
}