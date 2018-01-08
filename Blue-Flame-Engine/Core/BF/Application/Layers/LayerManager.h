#pragma once
#include <vector>
#include "BF/Application/Layers/Layer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			class BF_API LayerManager
			{
				private:
					std::vector<Layer> layers;

				public:
					LayerManager();
					~LayerManager();

					void AddLayer(const Layer& layer);
					void RemoveLayer(const Layer& layer);

					inline Layer& GetLayer(int index) { return layers[index]; }
					inline size_t GetSize() const { return layers.size(); }
			};
		}
	}
}