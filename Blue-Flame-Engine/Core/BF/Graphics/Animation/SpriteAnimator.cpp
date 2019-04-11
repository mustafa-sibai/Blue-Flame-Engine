#include "SpriteAnimator.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			SpriteAnimator::SpriteAnimator(SpriteAnimationData* spriteAnimationData) :
				spriteAnimationData(spriteAnimationData), play(false), loop(false), timer(0), currentKeyFrameIndex(0)
			{
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