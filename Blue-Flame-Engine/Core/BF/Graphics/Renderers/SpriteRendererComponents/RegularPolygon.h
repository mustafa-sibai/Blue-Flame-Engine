#pragma once
#include "BF/Graphics/Renderers/SpriteRendererComponents/Renderable.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Renderers
		{
			namespace SpriteRendererComponents
			{
				class BFE_API RegularPolygon : public Renderable<RegularPolygon>
				{
				private:
					float radius;
					int triangleCount;

				public:
					RegularPolygon(float radius, int triCount, BF::Graphics::Renderers::RenderLayer* renderLayer);
					/*
					@pivot:
					Center = 0, 0
					Top left = +1, -1
					Top right = -1, -1
					Bottom left = +1, +1
					Bottom left = -1, +1
					*/
					RegularPolygon(float radius, int triangleCount, const BF::Math::Vector2f& pivot, BF::Graphics::Renderers::RenderLayer* renderLayer);
					RegularPolygon(float radius, int triangleCount, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer);
					RegularPolygon(float radius, int triangleCount, const BF::Math::Vector2f& pivot, int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					~RegularPolygon();
				};
			}
		}
	}
}