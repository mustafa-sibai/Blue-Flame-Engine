#include "RendererLayer.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			using namespace BF::Graphics::Renderers;

			RendererLayer::RendererLayer()
			{
			}

			RendererLayer::~RendererLayer()
			{
			}

			void RendererLayer::Add(const Renderable& renderable)
			{
				renderables.emplace_back(renderable);
			}

			void RendererLayer::Remove(const Renderable& renderable)
			{
			}
		}
	}
}