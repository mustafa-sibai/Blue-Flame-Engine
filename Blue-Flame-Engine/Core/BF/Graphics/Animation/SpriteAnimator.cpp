#include "SpriteAnimator.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			SpriteAnimator::SpriteAnimator(SpriteAnimationData* spriteAnimationData, bool loop) :
				spriteAnimationData(spriteAnimationData), currentSprite(nullptr), play(false), loop(loop), timer(0), currentKeyFrameIndex(0), renderFrame(true)
			{
				IComponent::type = IComponent::Type::SpriteAnimator;
			}

			SpriteAnimator::~SpriteAnimator()
			{
			}

			void SpriteAnimator::Play()
			{
				play = true;
			}

			void SpriteAnimator::Pause()
			{
				play = false;
			}
		}
	}
}