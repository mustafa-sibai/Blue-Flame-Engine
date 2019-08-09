#include "Animator.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			Animator::Animator(AnimationController* animationController) :
				Component(IComponent::Type::Animator),
				animationController(animationController), currentSprite(nullptr)
			{
			}

			Animator::~Animator()
			{
			}
		}
	}
}