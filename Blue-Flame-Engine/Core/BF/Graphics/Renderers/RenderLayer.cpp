#include "RenderLayer.h"
#include <algorithm>

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			using namespace std;
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			RenderLayer::RenderLayer(const string& name, SortingOrder sortingOrder) :
				name(name), sortingOrder(sortingOrder)
			{
			}

			RenderLayer::~RenderLayer()
			{
			}

			void RenderLayer::Sort()
			{
				/*if (sortingOrder == SortingOrder::BackToFront)
					sort(renderables.begin(), renderables.end(), IRenderable::BackToFront());
				else if (sortingOrder == SortingOrder::BackToFrontRightToLeft)
					sort(renderables.begin(), renderables.end(), IRenderable::BackToFrontRightToLeft());*/
			}
		}
	}
}