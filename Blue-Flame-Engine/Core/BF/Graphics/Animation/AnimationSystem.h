#pragma once
#include <vector>
#include "BF/ECS/ISystem.h"
#include "BF/Graphics/Animation/Animation.h"
#include "BF/Graphics/Animation/Animator.h"
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
				std::vector<Animator*> animators;
				BF::Graphics::Renderers::RenderPipeline& renderPipeline;

			public:
				AnimationSystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline);
				~AnimationSystem();

				void PlayAnimation(BF::Graphics::Renderers::SpriteRendererComponents::Sprite* sprite, BF::Graphics::Animation::Animation* animation, double deltaTime);

				void Initialize()			  override;
				void Load()					  override;
				void PostLoad()				  override;
				void Update(double deltaTime) override;
				void Render()				  override;

				void AddAnimator(Animator* animator);
				void RemoveAnimator(Animator* animator);
			};
		}
	}
}