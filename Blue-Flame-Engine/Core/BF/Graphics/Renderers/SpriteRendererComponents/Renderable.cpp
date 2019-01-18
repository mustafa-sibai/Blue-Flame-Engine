#include "Renderable.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace BF::Math;
			using namespace BF::ECS;

			Renderable::Renderable(const Vector2i& size, const Vector2f& pivot, unsigned int zLayer, const Color& color, RenderableType renderableType) :
				Component(Component::Type::Renderable),
				size(size), pivot(pivot), zLayer(zLayer), color(color), renderableType(renderableType)
			{
			}

			Renderable::~Renderable()
			{
			}
		}
	}
}