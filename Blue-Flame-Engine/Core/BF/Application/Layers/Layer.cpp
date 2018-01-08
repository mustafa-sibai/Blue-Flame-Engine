#include "Layer.h"

namespace BF
{
	namespace Application
	{
		namespace Layers
		{
			using namespace std;

			Layer::Layer(const string& name) :
				name(name)
			{
			}

			Layer::~Layer()
			{
			}

			void Layer::Add(GameNode& gameNode)
			{
				gameNodes.emplace_back(&gameNode);
			}

			void Layer::Remove(GameNode& gameNode)
			{
			}
		}
	}
}