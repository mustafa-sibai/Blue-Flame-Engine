#include "AnimationSystem.h"
#include "BF/Graphics/Renderers/RenderPipeline.h"
#include "BF/IO/ResourceManager.h"
#include "BF/System/Debug.h"
#include "BF/Graphics/Animation/AnimationNode.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			using namespace BF::IO;
			using namespace BF::Math;
			using namespace BF::Graphics::API;
			using namespace BF::Graphics::Renderers;
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			AnimationSystem::AnimationSystem(RenderPipeline& renderPipeline) :
				renderPipeline(renderPipeline)
			{
			}

			AnimationSystem::~AnimationSystem()
			{
			}

			void AnimationSystem::PlayAnimation(Sprite* sprite, BF::Graphics::Animation::Animation* animation, double deltaTime)
			{
				/*if (animation->state == Animation::State::None)
				{
					sprite->SetTexture(animation->texture);
					sprite->size = Vector2i(animation->texture->GetTextureData()->width, animation->texture->GetTextureData()->height);
					sprite->SetScissorRectangle((*animation->sequence->keyframes)[0].scissorRectangle);
					animation->state = animation->state = Animation::State::Started;
				}

				if (animation->state == Animation::State::Ended)
					animation->state = Animation::State::Started;

				animation->timer += deltaTime;

				if (animation->renderFrame)
				{
					sprite->SetScissorRectangle((*animation->sequence->keyframes)[animation->currentKeyFrameIndex].scissorRectangle);
					animation->renderFrame = false;
				}

				if (animation->timer >= (*animation->sequence->keyframes)[animation->currentKeyFrameIndex].time)
				{
					animation->currentKeyFrameIndex++;

					if (animation->currentKeyFrameIndex >= (*animation->sequence->keyframes).size())
					{
						if (animation->loop)
						{
							animation->currentKeyFrameIndex = 0;
							animation->timer = 0;
						}
						else
							animation->currentKeyFrameIndex--;

						animation->state = Animation::State::Ended;
					}

					animation->renderFrame = true;
				}*/
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
					if (animators[i]->animationController->currentAnimationNode->type == IAnimationNode::Type::StartingNode)
					{
						animators[i]->animationController->currentAnimationNode = animators[i]->animationController->startingAnimationNode->transition->animationNode;
					}

					AnimationNode* node = (AnimationNode*)animators[i]->animationController->currentAnimationNode;
					PlayAnimation(animators[i]->currentSprite, node->animation, deltaTime);

					for (size_t j = 0; j < node->transitions.size(); j++)
					{
						bool transition = false;
						for (size_t k = 0; k < node->transitions[j]->conditions.size(); k++)
						{
							transition = node->transitions[j]->conditions[i]->Evaluate();
						}

						if (transition)
						{
							if (node->transitions[j]->hasToFinishAnimation)
							{
								if (node->animation->state == Animation::State::Ended)
								{
									animators[i]->animationController->currentAnimationNode = node->transitions[j]->animationNode;
								}
							}
							else
							{
								animators[i]->animationController->currentAnimationNode = node->transitions[j]->animationNode;
							}
						}
					}
				}
			}

			void AnimationSystem::Render()
			{
			}

			void AnimationSystem::AddAnimator(Animator* animator)
			{
				/*animators.emplace_back(animator);

				animator->currentSprite = (Sprite*)animator->gameObject->AddComponent(new Sprite(nullptr, Vector2f(0.5f, 0.5f), 0, renderPipeline.spriteRenderer->renderLayerManager.GetDefaultRenderLayer(), Rectangle(), Color::Whites::White()));;
				renderPipeline.AddRenderable(animator->currentSprite);*/
			}

			void AnimationSystem::RemoveAnimator(Animator* animator)
			{
			}
		}
	}
}