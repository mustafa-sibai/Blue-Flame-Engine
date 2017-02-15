#include "Grid.h"
#include <BF/Input/Mouse.h>
#include <BF/Math/Math.h>

namespace Editor
{
	using namespace BF::Math;
	using namespace BF::Graphics;
	using namespace BF::Graphics::Renderers;

	Grid::Grid(SpriteRenderer& spriteRenderer) :
		spriteRenderer(spriteRenderer)
	{
		width = 10;
		height = 10;
		tileWidth = 64;
		tileHeight = 64;
		position = Vector2(0, 0);

		rectangle = BF::Math::Rectangle(position.x, position.y, width * tileWidth, height * tileHeight);
	}

	Grid::~Grid()
	{
	}

	bool Grid::IsMouseInGrid()
	{
		return rectangle.Intersect(BF::Math::Rectangle(BF::Input::Mouse::GetPosition().x, BF::Input::Mouse::GetPosition().y, 1, 1));
	}

	void Grid::Render()
	{
		for (unsigned int x = 0; x < width + 1; x++)
		{
			linePosition = Vector2(position.x + (tileWidth * x), position.y);
			spriteRenderer.RenderLine(linePosition, Vector2(linePosition.x, linePosition.y + (height * tileHeight)), 1, Color(0.0f, 0.0f, 0.0f, 1.0f));
		}

		for (unsigned int y = 0; y < height + 1; y++)
		{
			linePosition = Vector2(position.x, position.y + (tileHeight * y));
			spriteRenderer.RenderLine(linePosition, Vector2(linePosition.x + (width * tileWidth), linePosition.y), 1, Color(0.0f, 0.0f, 0.0f, 1.0f));
		}
	}
}