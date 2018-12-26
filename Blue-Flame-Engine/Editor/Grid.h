#pragma once
#include <BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h>

namespace Editor
{
	class Grid
	{
		private:
			BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;
			BF::Math::Vector2f linePosition;
			BF::Math::Rectangle rectangle;

			std::vector<BF::Graphics::Renderers::LineShape> horizontalLines;
			std::vector<BF::Graphics::Renderers::LineShape> verticalLines;

		public:
			int tileWidth, tileHeight;

		public:
			Grid(BF::Math::Rectangle& rectangle);
			~Grid();

			bool IsMouseInGrid();
			void Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
			void Render();

			inline const BF::Math::Rectangle& GetRectangle() const { return rectangle; }
	};
}