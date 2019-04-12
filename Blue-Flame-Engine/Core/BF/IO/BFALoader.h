#pragma once
#include <string>
#include "BF/Graphics/Animation/SpriteAnimationData.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BFE_API BFALoader
		{
			public:
				static BF::Graphics::Animation::SpriteAnimationData* Load(const std::string& filename);
		};
	}
}