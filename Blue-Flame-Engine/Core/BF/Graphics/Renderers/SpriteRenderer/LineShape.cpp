#include "LineShape.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;

			/*LineShape::LineShape() :
				thickness(0)
			{
			}*/

			LineShape::LineShape(const Vector2f& startPoint, const Vector2f& endPoint, float thickness, unsigned int zLayer, const Color& color) :
				Renderable(Vector2i(), zLayer, color, RenderableType::Line), startPoint(startPoint), endPoint(endPoint), thickness(thickness)
			{
			}

			LineShape::~LineShape()
			{
			}
		}
	}
}