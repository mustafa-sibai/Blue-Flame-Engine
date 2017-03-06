#include "Grid.h"
#include <BF/Input/Mouse.h>
#include <BF/Math/Math.h>

namespace Editor
{
	using namespace BF;
	using namespace BF::Math;
	using namespace BF::Graphics;
	using namespace BF::Graphics::Renderers;

	Grid::Grid(Math::Rectangle& rectangle) : 
		rectangle(rectangle)
	{
		tileWidth = 64;
		tileHeight = 64;
	}

	Grid::~Grid()
	{
	}

	bool Grid::IsMouseInGrid()
	{
		return Math::Rectangle(rectangle.x, rectangle.y, rectangle.width * tileWidth, rectangle.height * tileHeight).Intersect(Math::Rectangle((int)BF::Input::Mouse::GetPosition().x, (int)BF::Input::Mouse::GetPosition().y, 1, 1));
	}

	void Grid::Initialize(SpriteRenderer& spriteRenderer)
	{
		this->spriteRenderer = &spriteRenderer;
	}

	void Grid::Render()
	{
		for (int x = 0; x < rectangle.width + 1; x++)
		{
			linePosition = Vector2(rectangle.x + (tileWidth * x), rectangle.y);
			spriteRenderer->RenderLine(linePosition, Vector2(linePosition.x, linePosition.y + (rectangle.height * tileHeight)), 1, Color(0.0f, 0.0f, 0.0f, 1.0f));
		}

		for (int y = 0; y < rectangle.height + 1; y++)
		{
			linePosition = Vector2(rectangle.x, rectangle.y + (tileHeight * y));
			spriteRenderer->RenderLine(linePosition, Vector2(linePosition.x + (rectangle.width * tileWidth), linePosition.y), 1, Color(0.0f, 0.0f, 0.0f, 1.0f));
		}
	}
}