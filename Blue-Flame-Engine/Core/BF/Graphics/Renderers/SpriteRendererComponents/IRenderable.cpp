#include "IRenderable.h"
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
				using namespace BF::ECS;
				using namespace BF::Graphics::Renderers;

				IRenderable::IRenderable(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					size(size), pivot(pivot), zSortingOrder(zSortingOrder), renderLayer(renderLayer), color(color), xySortingOrder(0)
				{
				}

				IRenderable::~IRenderable()
				{
				}
			}
		}
	}
}