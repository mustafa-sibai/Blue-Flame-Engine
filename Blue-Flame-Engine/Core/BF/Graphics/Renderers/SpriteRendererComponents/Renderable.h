#pragma once
#include "IRenderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				template <class T>
				class Renderable : public IRenderable
				{
				public:
					Renderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, unsigned int zLayer, const Color& color);
					virtual ~Renderable();
				};

#include "Renderable.inl"
			}
		}
	}
}