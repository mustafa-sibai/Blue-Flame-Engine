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
					Renderable(Type type, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					virtual ~Renderable();
				};

#include "Renderable.inl"
			}
		}
	}
}