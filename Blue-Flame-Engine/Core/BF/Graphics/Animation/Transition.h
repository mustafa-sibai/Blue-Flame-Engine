#pragma once
#include <vector>
#include "BF/Graphics/Animation/Condition.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class AnimationNode;

			class BFE_API Transition
			{
			public:
				AnimationNode* animationNode;
				std::vector<Condition*> conditions;
				bool hasToFinishAnimation;

				Transition(AnimationNode* animationNode, bool hasToFinishAnimation);
				~Transition();
			};
		}
	}
}