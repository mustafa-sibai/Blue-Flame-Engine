#include "Animator.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			Animator::Animator(AnimationController* animationController) :
				animationController(animationController), currentSprite(nullptr)
			{
				IComponent::type = IComponent::Type::Animator;
			}

			Animator::~Animator()
			{
			}
		}
	}
}