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
					sort(gameNodes.begin(), gameNodes.end(), SortingFunction());
					sortLayer = false;
				}
			}

			void Layer::Add(GameNode& gameNode)
			{
				gameNodes.emplace_back(&gameNode);
				sortLayer = true;
			}

			void Layer::Remove(GameNode& gameNode)
			{
			}
		}
	}
}