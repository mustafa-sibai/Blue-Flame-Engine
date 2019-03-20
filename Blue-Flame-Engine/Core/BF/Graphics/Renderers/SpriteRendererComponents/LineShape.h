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
				class BFE_API LineShape : public Renderable<LineShape>
				{
					friend class SpriteRenderer;

				private:
					BF::Math::Vector2f startPoint;
					BF::Math::Vector2f endPoint;
					float thickness;

				public:
					//LineShape();
					LineShape(const BF::Math::Vector2f& startPoint, const BF::Math::Vector2f& endPoint, BF::Graphics::Renderers::RenderLayer& renderLayer);
					LineShape(const BF::Math::Vector2f& startPoint, const BF::Math::Vector2f& endPoint, float thickness, BF::Graphics::Renderers::RenderLayer& renderLayer);
					LineShape(const BF::Math::Vector2f& startPoint, const BF::Math::Vector2f& endPoint, float thickness, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer);
					LineShape(const BF::Math::Vector2f& startPoint, const BF::Math::Vector2f& endPoint, float thickness, int zSortingOrder, BF::Graphics::Renderers::RenderLayer& renderLayer, const BF::Graphics::Color& color);
					~LineShape();
				};
			}
		}
	}
}