#pragma once
#include <string.h>
#include "BF/Graphics/Animation/SpriteAnimation.h"
#include "BF/Common.h"

namespace BF
{
	namespace IO
	{
		class BF_API BFALoader
		{
			public:
				static Graphics::Animation::SpriteAnimationData* Load(const std::string& filename);
		};
	}
}