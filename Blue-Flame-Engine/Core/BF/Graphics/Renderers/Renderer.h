#pragma once
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class BFE_API Renderer
			{
				friend class RenderPipeline;

			protected:
				enum class RendererType { None, SpriteRenderer, ForwardRenderer, PostProcessing, SkyboxRenderer };
				RendererType rendererType;

			public:
				Renderer(RendererType rendererType);
				~Renderer();

				virtual void Initialize();
				virtual void PostLoad();
				virtual void Update();
				virtual void Render();
			};
		}
	}
}