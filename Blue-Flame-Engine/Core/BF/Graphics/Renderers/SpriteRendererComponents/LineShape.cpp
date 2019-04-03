#include "LineShape.h"
#include "BF/Graphics/Renderers/RenderLayer.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace std;
				using namespace BF::Math;
				using namespace BF::Graphics::Renderers;

				/*LineShape::LineShape() :
					thickness(0)
				{
				}*/

				LineShape::LineShape(const Vector2f& startPoint, const Vector2f& endPoint, RenderLayer& renderLayer) :
					Renderable(Type::LineShape, Vector2i(), Vector2f(), 0, renderLayer, Color::Whites::White()), startPoint(startPoint), endPoint(endPoint), thickness(0)
				{
				}

				LineShape::LineShape(const Vector2f& startPoint, const Vector2f& endPoint, float thickness, RenderLayer& renderLayer) :
					Renderable(Type::LineShape, Vector2i(), Vector2f(), 0, renderLayer, Color::Whites::White()), startPoint(startPoint), endPoint(endPoint), thickness(thickness)
				{
				}

				LineShape::LineShape(const Vector2f& startPoint, const Vector2f& endPoint, float thickness, int zSortingOrder, RenderLayer& renderLayer) :
					Renderable(Type::LineShape, Vector2i(), Vector2f(), zSortingOrder, renderLayer, Color::Whites::White()), startPoint(startPoint), endPoint(endPoint), thickness(thickness)
				{
				}

				LineShape::LineShape(const Vector2f& startPoint, const Vector2f& endPoint, float thickness, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(Type::LineShape, Vector2i(), Vector2f(), zSortingOrder, renderLayer, color), startPoint(startPoint), endPoint(endPoint), thickness(thickness)
				{
				}

				LineShape::~LineShape()
				{
				}
			}
		}
	}
}