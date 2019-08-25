#pragma once
#include "BF/ECS/GameObject.h"
#include "BF/ECS/Component.h"
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/System/RenderableTransform.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class RenderLayer;
			class SpriteRenderer;

			namespace SpriteRendererComponents
			{
				class BFE_API IRenderable : public BF::ECS::Component<IRenderable>
				{
					friend class BF::Graphics::Renderers::RenderLayer;
					friend class BF::Graphics::Renderers::SpriteRenderer;

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
							if (renderableA->xySortingOrder < renderableB->xySortingOrder)
							{
								if (renderableA->zSortingOrder <= renderableB->zSortingOrder)
								{
									return true;
								}
							}

							if (renderableA->xySortingOrder >= renderableB->xySortingOrder)
							{
								if (renderableA->zSortingOrder < renderableB->zSortingOrder)
								{
									return true;
								}
							}

							return false;
						}
					};

				protected:
					enum class Type { None, Sprite, LineShape, RectangleShape, RegularPolygon, Text };
					Type type;

				public:
					BF::System::RenderableTransform* transfrom;
					int zSortingOrder;
					BF::Graphics::Renderers::RenderLayer* renderLayer;
					int xySortingOrder;
					Color color;

				public:
					IRenderable(Type type, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					virtual ~IRenderable();

					void SetSize(const BF::Math::Vector2i& size);
					void SetPivot(const BF::Math::Vector2f& pivot);
				};
			}
		}
	}
}