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
				class BFE_API RegularPolygon : public Renderable<RegularPolygon>
				{
				public:
					RegularPolygon(const BF::Math::Vector2i& size);
					/*
					@pivot:
					Center = 0, 0
					Top left = +1, -1
					Top right = -1, -1
					Bottom left = +1, +1
					Bottom left = -1, +1
					*/
					RegularPolygon(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot);
					RegularPolygon(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, unsigned int zLayer);
					RegularPolygon(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, unsigned int zLayer, const Color& color);
					~RegularPolygon();
				};
			}
		}
	}
}