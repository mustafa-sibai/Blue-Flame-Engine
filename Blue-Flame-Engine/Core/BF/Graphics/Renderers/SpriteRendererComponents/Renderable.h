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
					Renderable(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Graphics::Color& color);
					virtual ~Renderable();
				};

#include "Renderable.inl"
			}
		}
	}
}