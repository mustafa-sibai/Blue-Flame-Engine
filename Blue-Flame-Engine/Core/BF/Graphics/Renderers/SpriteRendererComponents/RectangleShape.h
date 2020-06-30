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
				class BFE_API RectangleShape : public Renderable<RectangleShape>
				{
				public:
					//BF::Math::Matrix4 worldTransformation;
					//BF::Math::Matrix4 transformation;

					BF::Math::Vector2f position;
					//BF::Math::Vector3f direction;
					//BF::Math::Vector3f rotation;
					//BF::Math::Vector3f scale;
					//BF::Math::Vector3f prevPos;
					//float angle;

					//BF::Math::Rectangle edges;
					BF::Math::Vector2i size;
					//BF::Math::Vector2f pivot;
					//BF::Math::Vector2f corners[4];

				public:
					//RectangleShape(const BF::Math::Vector2i& size, BF::Graphics::Renderers::RenderLayer* renderLayer);
					/*
					@pivot:
					Center = 0, 0
					Top left = +1, -1
					Top right = -1, -1
					Bottom left = +1, +1
					Bottom left = -1, +1
					*/
					//RectangleShape(const BF::Math::Vector2i& size, const BF::Math::Vector2f& pivot, BF::Graphics::Renderers::RenderLayer* renderLayer);
					RectangleShape(int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer);
					RectangleShape(int zSortingOrder, BF::Graphics::Renderers::RenderLayer* renderLayer, const BF::Graphics::Color& color);
					~RectangleShape();

					void SetPosition(BF::Math::Vector2i& size, BF::Math::Vector2f& pivot, BF::Math::Vector2f& position);
				};
			}
		}
	}
}