#pragma once
#include "BF/Graphics/Renderers/SpriteRendererComponents/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				class BFE_API LineShape : public Renderable<LineShape>
				{
					friend class SpriteRenderer;

				private:
					BF::Math::Vector2f startPoint;
					BF::Math::Vector2f endPoint;
					float thickness;

				public:
					//LineShape();
					LineShape(const BF::Math::Vector2f& startPoint, const BF::Math::Vector2f& endPoint, float thickness, unsigned int zLayer, const Color& color);
					~LineShape();
				};
			}
		}
	}
}