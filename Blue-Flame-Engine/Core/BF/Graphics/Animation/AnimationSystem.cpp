#include "AnimationSystem.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			AnimationSystem::AnimationSystem()
			{
			}

			AnimationSystem::~AnimationSystem()
			{
			}

			void AnimationSystem::Initialize()
			{
			}

			void AnimationSystem::Load()
			{
			}

			void AnimationSystem::PostLoad()
			{
			}

			void AnimationSystem::Update(double deltaTime)
			{
			}

			void AnimationSystem::Render()
			{
			}

			void AnimationSystem::AddSpriteAnimator(SpriteAnimator* spriteAnimator)
			{
				animators.emplace_back(spriteAnimator);
			}

			void AnimationSystem::RemoveSpriteAnimator(SpriteAnimator* spriteAnimator)
			{
			}
		}
	}
}