#pragma once
#include <BF/Graphics/Renderers/SpriteRenderer.h>

namespace Editor
{
	class Grid
	{
	private:
		BF::Graphics::Renderers::SpriteRenderer* spriteRenderer;
		BF::Math::Vector2 linePosition;
		BF::Math::Rectangle rectangle;

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