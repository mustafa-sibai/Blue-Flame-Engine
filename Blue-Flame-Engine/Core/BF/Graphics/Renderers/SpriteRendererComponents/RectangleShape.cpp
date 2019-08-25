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

				RectangleShape::RectangleShape(int zSortingOrder, RenderLayer* renderLayer) :
					Renderable(Type::RectangleShape, zSortingOrder, renderLayer, Color::Whites::White())
				{
				}

				RectangleShape::RectangleShape(int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Renderable(Type::RectangleShape, zSortingOrder, renderLayer, color)
				{
				}

				RectangleShape::~RectangleShape()
				{
				}
			}
		}
	}
}