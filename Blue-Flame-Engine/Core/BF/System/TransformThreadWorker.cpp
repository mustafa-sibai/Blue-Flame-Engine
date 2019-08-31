#include "TransformThreadWorker.h"
#include "BF/System/RenderableTransform.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace System
	{
		using namespace BF::Math;

		TransformThreadWorker::TransformThreadWorker(unsigned int beginning, unsigned int end, State state) :
			beginning(beginning), end(end), state(State::FrameInProgress)
		{
		}

		TransformThreadWorker::~TransformThreadWorker()
		{
		}


		void TransformThreadWorker::Execute(std::vector<Transform*>* transforms, TransformThreadWorker* transformThreadWorker)
		{
			float totalFrames = 0;
			float frames = 0;

			while (true)
			{
				if (transformThreadWorker->state == State::FinishedUpdatingTransforms)
					continue;

				transformThreadWorker->state = State::UpdatingTransformsInProgress;

				frames++;

				if (transformThreadWorker->timer.GetElapsedTimeInMilliseconds() >= 1000)
				{
					totalFrames = frames;
					std::cout << "thread fps: " << totalFrames << std::endl;
					frames = 0;
					transformThreadWorker->timer.Reset();
				}

				for (size_t i = transformThreadWorker->beginning; i < transformThreadWorker->end; i++)
				{
					if ((*transforms)[i]->updatePosition)
					{
						(*transforms)[i]->transformation =  Matrix4::Translate((*transforms)[i]->position) *
															Matrix4::Rotate((*transforms)[i]->angle, (*transforms)[i]->rotation) *
															Matrix4::Scale((*transforms)[i]->scale);

						(*transforms)[i]->position = (*transforms)[i]->transformation.GetTranslationVector();

						(*transforms)[i]->direction = ((*transforms)[i]->position - (*transforms)[i]->prevPos).Normalize();
						(*transforms)[i]->worldTransformation = (*transforms)[i]->worldTransformation * (*transforms)[i]->transformation;

						for (size_t j = 0; j < (*transforms)[i]->transformables.size(); j++)
						{
							if ((*transforms)[i]->transformables[j]->type == Transformable::Type::SpriteRendererTransform)
							{
								RenderableTransform* renderableTransform = (RenderableTransform*)(*transforms)[i]->transformables[j];

								if ((*transforms)[i]->transformables[j]->updatePivotAndSize)
								{
									Vector2i scaledSprite = Vector2i(renderableTransform->size.x * (*transforms)[i]->scale.x, renderableTransform->size.y * (*transforms)[i]->scale.y);
									renderableTransform->edges = BF::Math::Rectangle((*transforms)[i]->position.x, (*transforms)[i]->position.y, scaledSprite.x, scaledSprite.y, renderableTransform->pivot).GetEdgeOffsetByPivotAtOrigin();
									renderableTransform->updatePivotAndSize = false;
								}

								//Top Left
								renderableTransform->corners[0] = Vector2f((*transforms)[i]->position.x + renderableTransform->edges.x, renderableTransform->edges.y + (*transforms)[i]->position.y);

								//Top Right
								renderableTransform->corners[1] = Vector2f((*transforms)[i]->position.x + renderableTransform->edges.width, renderableTransform->edges.y + (*transforms)[i]->position.y);

								//Bottom Right
								renderableTransform->corners[2] = Vector2f((*transforms)[i]->position.x + renderableTransform->edges.width, renderableTransform->edges.height + (*transforms)[i]->position.y);

								//Bottom Left
								renderableTransform->corners[3] = Vector2f((*transforms)[i]->position.x + renderableTransform->edges.x, renderableTransform->edges.y + (*transforms)[i]->position.y);
							}
						}

						//IRenderable* renderable = transforms[i]->gameObject->GetComponent<IRenderable>();
						//renderable->transfrom = transforms[i];

						/*//-----
						IRenderable* renderable = transforms[i]->gameObject->GetComponent<IRenderable>();
						Vector2i scaledSprite = Vector2i(renderable->size.x * transforms[i]->scale.x, renderable->size.y * transforms[i]->scale.y);
						renderable->corners = BF::Math::Rectangle(transforms[i]->position.x, transforms[i]->position.y, scaledSprite.x, scaledSprite.y, renderable->pivot).GetCorners();
						//-----*/

						(*transforms)[i]->updatePosition = false;
					}
				}

				transformThreadWorker->state = State::FinishedUpdatingTransforms;
			}
		}
	}
}