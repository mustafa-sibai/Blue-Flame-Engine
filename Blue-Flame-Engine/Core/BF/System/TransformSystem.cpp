#include "TransformSystem.h"
#include "BF/Math/Matrix4.h"
#include "BF/ECS/GameObject.h"
#include "BF/Graphics/Renderers/SpriteRendererComponents/IRenderable.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace System
	{
		using namespace BF::Math;
		using namespace BF::Graphics::Renderers::SpriteRendererComponents;

		TransformSystem::TransformSystem()
		{
		}

		TransformSystem::~TransformSystem()
		{
		}

		void TransformSystem::Initialize()
		{
		}

		void TransformSystem::Load()
		{
		}

		void TransformSystem::PostLoad()
		{
		}

		void TransformSystem::Update(double deltaTime)
		{
			for (size_t i = 0; i < transforms.size(); i++)
			{
				if (transforms[i]->updatePosition)
				{
					//BFE_LOG_INFO(transforms[i]->position, "");

					transforms[i]->transformation = Matrix4::Translate(transforms[i]->position) * 
													Matrix4::Rotate(transforms[i]->angle, transforms[i]->rotation) * 
													Matrix4::Scale(transforms[i]->scale);

					transforms[i]->position = transforms[i]->transformation.GetTranslationVector();

					transforms[i]->direction = (transforms[i]->position - transforms[i]->prevPos).Normalize();
					transforms[i]->worldTransformation = transforms[i]->worldTransformation * transforms[i]->transformation;
					
					for (size_t j = 0; j < transforms[i]->transformables.size(); j++)
					{
						if (transforms[i]->transformables[j]->type == Transformable::Type::SpriteRendererTransform)
						{
							RenderableTransform* renderableTransform = (RenderableTransform*)transforms[i]->transformables[j];
							
							if (transforms[i]->transformables[j]->updatePivotAndSize)
							{
								Vector2i scaledSprite = Vector2i(renderableTransform->size.x * transforms[i]->scale.x, renderableTransform->size.y * transforms[i]->scale.y);
								renderableTransform->edges = BF::Math::Rectangle(transforms[i]->position.x, transforms[i]->position.y, scaledSprite.x, scaledSprite.y, renderableTransform->pivot).GetEdgeOffsetByPivotAtOrigin();
								renderableTransform->updatePivotAndSize = false;
							}

							//Top Left
							renderableTransform->corners[0] = Vector2f(transforms[i]->position.x + renderableTransform->edges.x, renderableTransform->edges.y + transforms[i]->position.y);
							
							//Top Right
							renderableTransform->corners[1] = Vector2f(transforms[i]->position.x + renderableTransform->edges.width,	renderableTransform->edges.y + transforms[i]->position.y);
							
							//Bottom Right
							renderableTransform->corners[2] = Vector2f(transforms[i]->position.x + renderableTransform->edges.width,	renderableTransform->edges.height + transforms[i]->position.y);
							
							//Bottom Left
							renderableTransform->corners[3] = Vector2f(transforms[i]->position.x + renderableTransform->edges.x,		renderableTransform->edges.y + transforms[i]->position.y);
						}
					}

					//IRenderable* renderable = transforms[i]->gameObject->GetComponent<IRenderable>();
					//renderable->transfrom = transforms[i];

					/*//-----
					IRenderable* renderable = transforms[i]->gameObject->GetComponent<IRenderable>();
					Vector2i scaledSprite = Vector2i(renderable->size.x * transforms[i]->scale.x, renderable->size.y * transforms[i]->scale.y);
					renderable->corners = BF::Math::Rectangle(transforms[i]->position.x, transforms[i]->position.y, scaledSprite.x, scaledSprite.y, renderable->pivot).GetCorners();
					//-----*/

					transforms[i]->updatePosition = false;
				}
			}
		}

		void TransformSystem::Render()
		{
		}

		void TransformSystem::AddTransform(Transform* transform)
		{
			transforms.emplace_back(transform);
		}

		void TransformSystem::RemoveTransform(Transform* transform)
		{
		}
	}
}