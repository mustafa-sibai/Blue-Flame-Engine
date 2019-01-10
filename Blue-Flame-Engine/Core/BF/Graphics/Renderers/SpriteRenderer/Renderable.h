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
			class BF_API Renderable : public BF::ECS::Component
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
							if (renderableA->gameObject->GetTransform()->position.y <= renderableB->gameObject->GetTransform()->position.y)
							{
								if (renderableA->zLayer < renderableB->zLayer)
								{
									return true;
								}
							}

							if (renderableA->gameObject->GetTransform()->position.y < renderableB->gameObject->GetTransform()->position.y)
							{
								if (renderableA->zLayer == renderableB->zLayer)
								{
									return true;
								}
							}

							if (renderableA->gameObject->GetTransform()->position.y >= renderableB->gameObject->GetTransform()->position.y)
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
					unsigned int zLayer;
					Color color;

				public:
					//Renderable();
					Renderable(const BF::Math::Vector2i& size, unsigned int zLayer, const Color& color, RenderableType renderableType);
					~Renderable();

					//virtual void SetPosition(const BF::Math::Vector2f& position);
					//virtual void SetRectangle(const BF::Math::Rectangle& rectangle);

					//inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
			};
		}
	}
}