#pragma once
#include "BF/Application/Component.h"
#include "BF/Graphics/Color.h"
#include "BF/Math/Math.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API Renderable : public BF::Application::Component
			{
				friend class SpriteRenderer;

				protected:
					BF::Math::Vector2f position;
					BF::Math::Rectangle rectangle;

					enum class RenderableType { Null, Line, RegularPolygon, Sprite, Text };
					RenderableType renderableType;

				public:
					Color color;
					unsigned int zLayer;

				public:
					Renderable();
					Renderable(const BF::Math::Vector2f& position, const BF::Math::Rectangle& rectangle, unsigned int zLayer, const Color& color, RenderableType renderableType);
					~Renderable();

					virtual void SetPosition(const BF::Math::Vector2f& position);
					virtual void SetRectangle(const BF::Math::Rectangle& rectangle);

					inline const BF::Math::Vector2f& GetPosition() const { return position; }
					inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
			};
		}
	}
}