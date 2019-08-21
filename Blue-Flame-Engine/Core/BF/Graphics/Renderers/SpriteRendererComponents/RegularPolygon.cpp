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

				RegularPolygon::RegularPolygon(float radius, int triangleCount, RenderLayer* renderLayer) :
					Renderable(Type::RegularPolygon, Vector2i(radius), Vector2f(0.5f), 0, renderLayer, Color::Whites::White()),
					radius(radius), triangleCount(triangleCount)
				{
				}

				RegularPolygon::RegularPolygon(float radius, int triangleCount, const Vector2f& pivot, RenderLayer* renderLayer) :
					Renderable(Type::RegularPolygon, Vector2i(radius), pivot, 0, renderLayer, Color::Whites::White()),
					radius(radius), triangleCount(triangleCount)
				{
				}

				RegularPolygon::RegularPolygon(float radius, int triangleCount, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::RegularPolygon, Vector2i(radius), pivot, zSortingOrder, renderLayer, Color::Whites::White()),
					radius(radius), triangleCount(triangleCount)
				{
				}

				RegularPolygon::RegularPolygon(float radius, int triangleCount, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::RegularPolygon, Vector2i(radius), pivot, zSortingOrder, renderLayer, color),
					radius(radius), triangleCount(triangleCount)
				{
				}

				RegularPolygon::~RegularPolygon()
				{
				}
			}
		}
	}
}