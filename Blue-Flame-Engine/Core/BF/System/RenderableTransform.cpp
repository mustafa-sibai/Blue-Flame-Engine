#include "RenderableTransform.h"

namespace BF
{
	namespace System
	{
		using namespace BF::Math;

		RenderableTransform::RenderableTransform(Vector2i& size, Vector2f& pivot) :
			Transformable(Type::SpriteRendererTransform),
			size(size), pivot(pivot)
		{
			updatePivotAndSize = true;
		}

		RenderableTransform::~RenderableTransform()
		{
		}
	}
}