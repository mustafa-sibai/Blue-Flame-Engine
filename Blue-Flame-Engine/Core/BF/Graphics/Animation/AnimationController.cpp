#include "AnimationController.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			AnimationController::AnimationController() :
				startingAnimationNode(new StartingAnimationNode()), currentAnimationNode(startingAnimationNode)
			{
			}

			AnimationController::~AnimationController()
			{
			}
		}
	}
}