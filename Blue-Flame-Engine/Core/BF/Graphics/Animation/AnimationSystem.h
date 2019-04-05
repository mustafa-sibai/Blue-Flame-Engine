#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
#include "BF/Graphics/Animation/SpriteAnimator.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			class BFE_API AnimationSystem : public BF::ECS::ISystem
			{
			private:
				std::vector<BF::Graphics::Animation::SpriteAnimator*> animators;

			public:
				AnimationSystem();
				~AnimationSystem();

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddSpriteAnimator(BF::Graphics::Animation::SpriteAnimator* spriteAnimator);
				void RemoveSpriteAnimator(BF::Graphics::Animation::SpriteAnimator* spriteAnimator);
			};
		}
	}
}