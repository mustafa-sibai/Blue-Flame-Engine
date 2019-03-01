#pragma once
#include "BF/ECS/GameObject.h"
#include "BF/ECS/Component.h"
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				class BFE_API IRenderable : public BF::ECS::Component<IRenderable>
				{
					friend class SpriteRenderer;

				private:
					//Left right - back front
					struct BackToFront
					{
						bool operator() (const IRenderable* renderableA, const IRenderable* renderableB) const
						{
							if (renderableA->gameObject->GetTransform()->GetPosition().y <= renderableB->gameObject->GetTransform()->GetPosition().y)
							{
								if (renderableA->zSortingOrder < renderableB->zSortingOrder)
								{
									return true;
								}
							}

							if (renderableA->gameObject->GetTransform()->GetPosition().y >= renderableB->gameObject->GetTransform()->GetPosition().y)
							{
								if (renderableA->zSortingOrder < renderableB->zSortingOrder)
								{
									return true;
								}
							}

							/*if (renderableA->gameObject->GetTransform()->GetPosition().y < renderableB->gameObject->GetTransform()->GetPosition().y)
							{
								if (renderableA->zLayer == renderableB->zLayer)
								{
									return false;
								}
							}*/



							return false;
						}
					};

					struct BackToFrontRightToLeft
					{
						bool operator() (const IRenderable* renderableA, const IRenderable* renderableB) const
						{
							if (renderableA->xySortingOrder > renderableB->xySortingOrder)
							{
								if (renderableA->zSortingOrder == renderableB->zSortingOrder)
								{
									return true;
								}
							}
							



							/*if (renderableA->gameObject->GetTransform()->GetPosition().y >= renderableB->gameObject->GetTransform()->GetPosition().y)
							{
								if (renderableA->zLayer < renderableB->zLayer)
								{
									return true;
								}
							}*/

							/*if (renderableA->gameObject->GetTransform()->GetPosition().y < renderableB->gameObject->GetTransform()->GetPosition().y)
							{
								if (renderableA->zLayer == renderableB->zLayer)
								{
									return false;
								}
							}*/



							return false;
						}
					};

				public:
					BF::Math::Vector2i size;
					BF::Math::Vector2f pivot;
					int xySortingOrder;
					int zSortingOrder;
					Color color;

				public:
					IRenderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, int zSortingOrder, const Color& color);
					virtual ~IRenderable();
				};
			}
		}
	}
}