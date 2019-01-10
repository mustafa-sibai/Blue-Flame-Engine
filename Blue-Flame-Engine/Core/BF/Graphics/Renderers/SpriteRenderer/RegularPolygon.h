#pragma once
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BF_API RegularPolygon : public Renderable
			{
				public:
					//RegularPolygon();
					RegularPolygon(const BF::Math::Vector2i& size, unsigned int zLayer, const Color& color);
					~RegularPolygon();
			};
		}
	}
}