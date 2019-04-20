#pragma once
#include "BF/ECS/Component.h"
#include "BF/Graphics/Animation/AnimationController.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/Sprite.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class AnimationSystem;

			class BFE_API Animator : public BF::ECS::Component<Animator>
			{
				friend class BF::Graphics::Animation::AnimationSystem;

			private:
				AnimationController* animationController;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite* currentSprite;

			public:
				Animator(AnimationController* animationController);
				~Animator();
			};
		}
	}
}