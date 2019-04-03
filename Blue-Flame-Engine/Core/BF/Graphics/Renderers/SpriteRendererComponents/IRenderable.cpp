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

				IRenderable::IRenderable(Type type, const Vector2i& size, const Vector2f& pivot, int zSortingOrder, RenderLayer& renderLayer, const Color& color) :
					type(type), size(size), pivot(pivot), zSortingOrder(zSortingOrder), renderLayer(renderLayer), color(color), xySortingOrder(0)
				{
					IComponent::type = IComponent::Type::Renderable;
				}

				IRenderable::~IRenderable()
				{
				}
			}
		}
	}
}