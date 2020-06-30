#pragma once
#include <vector>
#include "BF/Graphics/Renderers/RenderLayer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API RenderLayerManager
			{
				friend class BF::Graphics::Renderers::SpriteRenderer;

			private:
				std::vector<BF::Graphics::Renderers::RenderLayer> renderLayers;

			public:
				RenderLayerManager();
				~RenderLayerManager();

				BF::Graphics::Renderers::RenderLayer& AddRenderLayer(BF::Graphics::Renderers::RenderLayer& renderLayer);
				void RemoveRenderLayer(const std::string& name);

				BF::Graphics::Renderers::RenderLayer& GetRenderLayer(const std::string& name);
				inline BF::Graphics::Renderers::RenderLayer& GetDefaultRenderLayer() { return renderLayers[0]; }
				inline BF::Graphics::Renderers::RenderLayer& GetGUIRenderLayer() { return renderLayers[1]; }
			};
		}
	}
}