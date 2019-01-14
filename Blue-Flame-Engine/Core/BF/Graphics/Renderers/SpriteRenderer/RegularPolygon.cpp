#include "RegularPolygon.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;

			RegularPolygon::RegularPolygon(const Vector2i& size) :
				Renderable(size, Vector2f(0), 0, Color::Whites::White(), RenderableType::RegularPolygon)
			{
			}

			RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot) :
				Renderable(size, pivot, 0, Color::Whites::White(), RenderableType::RegularPolygon)
			{
			}

			RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot, unsigned int zLayer) :
				Renderable(size, pivot, zLayer, Color::Whites::White(), RenderableType::RegularPolygon)
			{
			}

			RegularPolygon::RegularPolygon(const Vector2i& size, const Vector2f& pivot, unsigned int zLayer, const Color& color) :
				Renderable(size, pivot, zLayer, color, RenderableType::RegularPolygon)
			{
			}

			RegularPolygon::~RegularPolygon()
			{
			}
		}
	}
}