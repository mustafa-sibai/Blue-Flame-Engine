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
				BF::Graphics::Animation::SpriteAnimationData* spriteAnimationData;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite* currentSprite;

				bool play;
				float timer;
				int currentKeyFrameIndex;
				bool renderFrame;

			public:
				bool loop;

			public:
				SpriteAnimator(BF::Graphics::Animation::SpriteAnimationData* spriteAnimationData, bool loop);
				~SpriteAnimator();

				void Play();
				void Pause();
			};
		}
	}
}