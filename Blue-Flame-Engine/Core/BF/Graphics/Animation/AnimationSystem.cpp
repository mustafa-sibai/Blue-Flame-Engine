#include "AnimationSystem.h"
#include "BF/Graphics/Renderers/RenderPipeline.h"
#include "BF/IO/ResourceManager.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			using namespace BF::IO;
			using namespace BF::Math;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			AnimationSystem::AnimationSystem(BF::Graphics::Renderers::RenderPipeline& renderPipeline) :
				renderPipeline(renderPipeline)
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
				for (size_t i = 0; i < animators.size(); i++)
				{
					animators[i]->timer += deltaTime;

					if (animators[i]->renderFrame)
					{
						animators[i]->currentSprite->SetScissorRectangle(animators[i]->spriteAnimationData->keyFrames[animators[i]->currentKeyFrameIndex].scissorRectangle);
						animators[i]->renderFrame = false;
					}

					if (animators[i]->timer >= animators[i]->spriteAnimationData->keyFrames[animators[i]->currentKeyFrameIndex].time)
					{
						animators[i]->currentKeyFrameIndex++;

						if (animators[i]->currentKeyFrameIndex >= animators[i]->spriteAnimationData->keyFrames.size())
						{
							if (animators[i]->loop)
							{
								animators[i]->currentKeyFrameIndex = 0;
								animators[i]->timer = 0;
							}
							else
								animators[i]->currentKeyFrameIndex--;
						}

						animators[i]->renderFrame = true;
					}
				}
			}

			void AnimationSystem::Render()
			{
			}

			void AnimationSystem::AddSpriteAnimator(SpriteAnimator* spriteAnimator)
			{
				animators.emplace_back(spriteAnimator);

				Texture2D* texture = new Texture2D();
				texture->Create(ResourceManager::Load<TextureData>(spriteAnimator->spriteAnimationData->textureName), Texture::Format::R8G8B8A8);

				Sprite* sprite = (Sprite*)spriteAnimator->gameObject->AddComponent(new Sprite(texture, Vector2f(0.5f, 0.5f), 0, *renderPipeline.spriteRenderer->renderLayerManager.GetDefaultRenderLayer(), spriteAnimator->spriteAnimationData->keyFrames[0].scissorRectangle, Color::Whites::White()));

				spriteAnimator->currentSprite = sprite;
				renderPipeline.AddRenderable(spriteAnimator->currentSprite);
			}

			void AnimationSystem::RemoveSpriteAnimator(SpriteAnimator* spriteAnimator)
			{
			}
		}
	}
}