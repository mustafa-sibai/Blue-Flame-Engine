#include "RectangleShape.h"
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

				RectangleShape::RectangleShape(const Vector2i& size, RenderLayer* renderLayer) :
					Renderable(Type::RectangleShape, size, Vector2f(0.5f), 0, renderLayer, Color::Whites::White())
				{
				}

				RectangleShape::RectangleShape(const Vector2i& size, const Vector2f& pivot, RenderLayer* renderLayer) :
					Renderable(Type::RectangleShape, size, pivot, 0, renderLayer, Color::Whites::White())
				{
				}

				RectangleShape::RectangleShape(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::RectangleShape, size, pivot, zSortingOrder, renderLayer, Color::Whites::White())
				{
				}

				RectangleShape::RectangleShape(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::RectangleShape, size, pivot, zSortingOrder, renderLayer, color)
				{
				}

				RectangleShape::~RectangleShape()
				{
				}
			}
		}
	}
}