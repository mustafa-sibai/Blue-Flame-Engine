#pragma once
#include "BF/ECS/ISystem.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			class RenderPipeline;

			class BFE_API IRenderer : public BF::ECS::ISystem
			{
				friend class BF::Graphics::Renderers::RenderPipeline;

			protected:
				enum class RendererType { None, SpriteRenderer, ForwardRenderer, PostProcessing, SkyboxRenderer };
				RendererType rendererType;

			public:
				IRenderer(RendererType rendererType);
				virtual ~IRenderer();
			};
		}
	}
}