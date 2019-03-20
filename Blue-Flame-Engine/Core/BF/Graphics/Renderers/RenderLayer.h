#pragma once
#include <string>
#include "BF/Graphics/Renderers/SpriteRendererComponents/IRenderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class RenderLayerManager;
			class SpriteRenderer;

			class BFE_API RenderLayer
			{
				friend class BF::Graphics::Renderers::RenderLayerManager;
				friend class BF::Graphics::Renderers::RenderPipeline;
				friend class BF::Graphics::Renderers::SpriteRenderer;

			private:
				std::string name;
				std::vector<BF::Graphics::Renderers::SpriteRendererComponents::IRenderable*> renderables;

			public:
				enum class SortingOrder { BackToFront, BackToFrontRightToLeft };
				SortingOrder sortingOrder;

			public:
				RenderLayer(const std::string& name, SortingOrder sortingOrder);
				~RenderLayer();

				void Sort();
			};
		}
	}
}