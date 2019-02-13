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

				IRenderable::IRenderable(const Vector2i& size, const Vector2f& pivot, unsigned int zLayer, const Color& color) :
					size(size), pivot(pivot), zLayer(zLayer), color(color)
				{
				}

				IRenderable::~IRenderable()
				{
				}
			}
		}
	}
}