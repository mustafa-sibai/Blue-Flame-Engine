#pragma once
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
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
					Math::Vector2f startPoint;
					Math::Vector2f endPoint;
					float thickness;

				public:
					LineShape();
					LineShape(const Math::Vector2f& startPoint, const Math::Vector2f& endPoint, float thickness, unsigned int zLayer, const Color& color);
					~LineShape();
			};
		}
	}
}