#include "RenderLayerManager.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;

			RenderLayerManager::RenderLayerManager()
			{
				renderLayers.emplace_back(RenderLayer("Default", RenderLayer::SortingOrder::BackToFront));
				renderLayers.emplace_back(RenderLayer("GUI", RenderLayer::SortingOrder::BackToFront));
			}

			RenderLayerManager::~RenderLayerManager()
			{
			}

			BF::Graphics::Renderers::RenderLayer& RenderLayerManager::AddRenderLayer(RenderLayer& renderLayer)
			{
				renderLayers.emplace_back(renderLayer);
				return renderLayers[renderLayers.size()];
			}

			void RenderLayerManager::RemoveRenderLayer(const string& name)
			{
				for (vector<RenderLayer>::iterator it = renderLayers.begin(); it != renderLayers.end(); ++it)
				{
					if (it->name == name)
					{
						renderLayers.erase(it);
						break;
					}
				}
			}

			RenderLayer& RenderLayerManager::GetRenderLayer(const string& name)
			{
				for (vector<RenderLayer>::iterator it = renderLayers.begin(); it != renderLayers.end(); ++it)
				{
					if (it->name == name)
					{
						return *it;
					}
				}
			}
		}
	}
}