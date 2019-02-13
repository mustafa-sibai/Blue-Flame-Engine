#pragma once
#include <vector>
#include "BF/Graphics/Renderers/SpriteRenderer/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class BF_API RendererLayer
			{
				private:
					std::vector<BF::Graphics::Renderers::Renderable*> renderables;

				public:
					RendererLayer();
					~RendererLayer();

					void Add(const BF::Graphics::Renderers::Renderable& renderable);
					void Remove(const BF::Graphics::Renderers::Renderable& renderable);
			};
		}
	}
}