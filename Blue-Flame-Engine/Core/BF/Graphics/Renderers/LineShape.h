#pragma once
#include "BF/Graphics/Renderers/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API LineShape : public Renderable
			{
				friend class SpriteRenderer;

				private:
					Math::Vector2 startPoint;
					Math::Vector2 endPoint;
					float thickness;

				public:
					LineShape();
					LineShape(const Math::Vector2& startPoint, const Math::Vector2& endPoint, float thickness, unsigned int zLayer, const Color& color);
					~LineShape();
			};
		}
	}
}