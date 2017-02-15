#pragma once
#include <BF/Graphics/Renderers/SpriteRenderer.h>

namespace Editor
{
	class Grid
	{
	private:
		BF::Graphics::Renderers::SpriteRenderer& spriteRenderer;
		BF::Math::Vector2 position;
		BF::Math::Vector2 linePosition;
		BF::Math::Rectangle rectangle;

	public:
		unsigned int width, height;
		unsigned int tileWidth, tileHeight;

	public:
		Grid(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer);
		~Grid();

		bool IsMouseInGrid();
		void Render();
	};
}