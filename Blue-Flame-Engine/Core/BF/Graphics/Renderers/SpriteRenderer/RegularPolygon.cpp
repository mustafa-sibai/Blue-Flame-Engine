#include "RegularPolygon.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;

			/*RegularPolygon::RegularPolygon()
			{
			}*/

			RegularPolygon::RegularPolygon(const BF::Math::Vector2i& size, unsigned int zLayer, const Color& color) :
				Renderable(size, zLayer, color, RenderableType::RegularPolygon)
			{
			}

			RegularPolygon::~RegularPolygon()
			{
			}
		}
	}
}