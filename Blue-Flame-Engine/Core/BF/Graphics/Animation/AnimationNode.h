#pragma once
#include <vector>
#include "BF/Graphics/Animation/IAnimationNode.h"
#include <BF/Graphics/Animation/Animation.h>
#include "BF/Graphics/Animation/Transition.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API AnimationNode : public IAnimationNode
			{
			public:
				Animation* animation;
				std::vector<Transition*> transitions;

				AnimationNode();
				~AnimationNode();
			};
		}
	}
}