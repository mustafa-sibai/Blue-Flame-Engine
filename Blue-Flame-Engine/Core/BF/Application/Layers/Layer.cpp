#include "Layer.h"
#include <algorithm>

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			using namespace std;

			Layer::Layer(const string& name) :
				name(name), sortLayer(false)
			{
			}

			Layer::~Layer()
			{
			}

			void Layer::Update()
			{
				if (sortLayer)
				{
					sort(components.begin(), components.end(), SortingFunction());
					sortLayer = false;
				}
			}

			void Layer::AddComponent(Component& component)
			{
				components.emplace_back(&component);
				sortLayer = true;
			}

			void Layer::RemoveComponent(Component& component)
			{
			}
		}
	}
}