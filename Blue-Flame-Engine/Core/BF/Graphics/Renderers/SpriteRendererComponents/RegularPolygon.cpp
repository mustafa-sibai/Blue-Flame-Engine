#include "RegularPolygon.h"
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

				RegularPolygon::RegularPolygon(const Vector2i& size, RenderLayer& renderLayer) :
					Renderable(Type::RegularPolygon, size, Vector2f(0.5f), 0, renderLayer, Color::Whites::White())
				{
				}

				RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot, RenderLayer& renderLayer) :
					Renderable(Type::RegularPolygon, size, pivot, 0, renderLayer, Color::Whites::White())
				{
				}

				RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer) :
					Renderable(Type::RegularPolygon, size, pivot, zSortingOrder, renderLayer, Color::Whites::White())
				{
				}

				RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					Renderable(Type::RegularPolygon, size, pivot, zSortingOrder, renderLayer, color)
				{
				}

				RegularPolygon::~RegularPolygon()
				{
				}
			}
		}
	}
}