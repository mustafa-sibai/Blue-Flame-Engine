#pragma once
#include "BF/Graphics/Renderers/Renderable.h"
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
					RegularPolygon();
					RegularPolygon(const Math::Rectangle& rectangle, unsigned int zLayer, const Color& color);
					~RegularPolygon();
			};
		}
	}
}