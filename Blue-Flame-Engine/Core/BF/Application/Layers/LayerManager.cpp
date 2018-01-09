#include "LayerManager.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			LayerManager::LayerManager()
			{
				layers.reserve(32);
				layers.emplace_back(Layer("Default"));
				layers.emplace_back(Layer("UI"));
			}

			LayerManager::~LayerManager()
			{
			}

			void LayerManager::Update()
			{
				for (size_t i = 0; i < layers.size(); i++)
					layers[i].Update();
			}

			void LayerManager::AddLayer(const Layer& layer)
			{
				layers.emplace_back(layer);
			}

			void LayerManager::RemoveLayer(const Layer& layer)
			{
			}
		}
	}
}