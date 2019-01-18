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
			class BFE_API Renderable : public BF::ECS::Component
			{
				friend class SpriteRenderer;

			protected:
				enum class RenderableType { Null, Line, RegularPolygon, Sprite, Text };
				RenderableType renderableType;

			private:
				struct BackToFront
				{
					bool operator() (const Renderable* renderableA, const Renderable* renderableB) const
					{
						if (renderableA->gameObject->GetTransform()->GetPosition().y <= renderableB->gameObject->GetTransform()->GetPosition().y)
						{
							if (renderableA->zLayer < renderableB->zLayer)
							{
								return true;
							}
						}

						if (renderableA->gameObject->GetTransform()->GetPosition().y < renderableB->gameObject->GetTransform()->GetPosition().y)
						{
							if (renderableA->zLayer == renderableB->zLayer)
							{
								return true;
							}
						}

						if (renderableA->gameObject->GetTransform()->GetPosition().y >= renderableB->gameObject->GetTransform()->GetPosition().y)
						{
							if (renderableA->zLayer < renderableB->zLayer)
							{
								return true;
							}
						}

						return false;
					}
				};

			public:
				BF::Math::Vector2i size;
				BF::Math::Vector2f pivot;
				unsigned int zLayer;
				Color color;

			public:
				Renderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, unsigned int zLayer, const Color& color, RenderableType renderableType);
				~Renderable();
			};
		}
	}
}