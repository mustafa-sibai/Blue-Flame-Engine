#pragma once
#include "BF/ECS/Component.h"
#include "BF/Graphics/Animation/SpriteAnimationData.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"

#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class AnimationSystem;

			class BFE_API SpriteAnimator : public BF::ECS::Component<SpriteAnimator>
			{
				friend class BF::Graphics::Animation::AnimationSystem;

			private:
				SpriteAnimationData* spriteAnimationData;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite* currentSprite;

				bool play;
				float timer;
				int currentKeyFrameIndex;

			public:
				bool loop;

			public:
				SpriteAnimator(SpriteAnimationData* spriteAnimationData);
				~SpriteAnimator();

				void Play();
				void Pause();
			};
		}
	}
}