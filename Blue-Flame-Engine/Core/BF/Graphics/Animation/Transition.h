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
				std::vector<Condition*> conditions;
				BF::Graphics::Animation::AnimationNode* transitionToNode;

				Transition(BF::Graphics::Animation::AnimationNode* transitionToNode);
				~Transition();
			};
		}
	}
}