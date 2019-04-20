#pragma once
#include <vector>
#include "BF/Graphics/Animation/IAnimationNode.h"
#include "BF/Graphics/Animation/Transition.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API StartingAnimationNode : public IAnimationNode
			{
			public:
				Transition* transition;

				StartingAnimationNode();
				~StartingAnimationNode();
			};
		}
	}
}