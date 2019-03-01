#include "IRenderable.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				using namespace BF::Math;
				using namespace BF::ECS;

				IRenderable::IRenderable(const Vector2i& size, const Vector2f& pivot, int zSortingOrder, const Color& color) :
					size(size), pivot(pivot), zSortingOrder(zSortingOrder), color(color)
				{
				}

				IRenderable::~IRenderable()
				{
				}
			}
		}
	}
}