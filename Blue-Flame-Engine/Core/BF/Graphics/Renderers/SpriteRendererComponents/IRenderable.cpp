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

				IRenderable::IRenderable(Type type, int zSortingOrder, RenderLayer* renderLayer, const Color& color) :
					Component(IComponent::Type::Renderable),
					type(type), zSortingOrder(zSortingOrder), /*renderLayer(renderLayer),*/ color(color), xySortingOrder(0)//, transfrom(nullptr)
				{
				}

				IRenderable::~IRenderable()
				{
				}

				void IRenderable::SetSize(const Vector2i& size)
				{
					/*transfrom->size = size;
					transfrom->updatePivotAndSize = true;*/
				}

				void IRenderable::SetPivot(const Vector2f& pivot)
				{
					/*transfrom->pivot = pivot;
					transfrom->updatePivotAndSize = true;*/
				}
			}
		}
	}
}