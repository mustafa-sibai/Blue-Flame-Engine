#pragma once
#include <vector>
#include <BF/Graphics/Animation/SpriteAnimator.h>
#include "BF/Graphics/Animation/Transition.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API AnimationNode
			{
			public:
				SpriteAnimator* spriteAnimator;
				std::vector<BF::Graphics::Animation::Transition*> transitions;

				AnimationNode();
				~AnimationNode();
			};
		}
	}
}