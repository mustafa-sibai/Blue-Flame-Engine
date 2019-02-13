#include "Grid.h"
#include <BF/Input/Mouse.h>
#include <BF/Math/Math.h>

namespace Editor
{
	using namespace BF;
	using namespace BF::Math;
	using namespace BF::Input;
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
		return Math::Rectangle(rectangle.x, rectangle.y, rectangle.width * tileWidth, rectangle.height * tileHeight).Intersect(Math::Rectangle((int)Mouse::GetPosition().x, (int)Mouse::GetPosition().y, 1, 1));
	}

	void Grid::Initialize(SpriteRenderer& spriteRenderer)
	{
		this->spriteRenderer = &spriteRenderer;

		for (int x = 0; x < rectangle.width + 1; x++)
		{
			linePosition = Vector2f(rectangle.x + (tileWidth * x), rectangle.y);
			horizontalLines.push_back(LineShape(linePosition, Vector2f(linePosition.x, linePosition.y + (rectangle.height * tileHeight)), 1, 0, Color(0.0f, 0.0f, 0.0f, 1.0f)));
		}

		for (int y = 0; y < rectangle.height + 1; y++)
		{
			linePosition = Vector2f(rectangle.x, rectangle.y + (tileHeight * y));
			verticalLines.push_back(LineShape(linePosition, Vector2f(linePosition.x + (rectangle.width * tileWidth), linePosition.y), 1, 0, Color(0.0f, 0.0f, 0.0f, 1.0f)));
		}
	}

	void Grid::Render()
	{
		for (size_t i = 0; i < horizontalLines.size(); i++)
			spriteRenderer->Render(horizontalLines[i]);

		for (size_t i = 0; i < verticalLines.size(); i++)
			spriteRenderer->Render(verticalLines[i]);
	}
}