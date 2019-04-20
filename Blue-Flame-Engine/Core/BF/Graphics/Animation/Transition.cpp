#include "Transition.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			Transition::Transition(AnimationNode* animationNode, bool hasToFinishAnimation) :
				animationNode(animationNode), hasToFinishAnimation(hasToFinishAnimation)
			{
			}

			Transition::~Transition()
			{
			}
		}
	}
}