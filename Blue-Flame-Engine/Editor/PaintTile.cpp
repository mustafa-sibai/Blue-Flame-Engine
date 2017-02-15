#include "PaintTile.h"
#include <BF/Input/Mouse.h>
#include <BF/System/Log.h>

namespace Editor
{
	using namespace BF::Graphics::Renderers;
	using namespace BF::Input;
	using namespace BF::Math;

	PaintTile::PaintTile(SpriteRenderer& spriteRenderer, Grid& grid, Editor::TileMap& tileMap) :
		spriteRenderer(spriteRenderer), grid(grid), tileMap(tileMap)
	{
	}


	PaintTile::~PaintTile()
	{
	}

	void PaintTile::SetCurrentTile(Sprite currentTile)
	{
		this->currentTile = currentTile;
	}

	void PaintTile::Update()
	{
		Vector2 indexedPosition = Vector2((int)(Mouse::GetPosition().x / grid.tileWidth), (int)(Mouse::GetPosition().y / grid.tileHeight));
		Vector2 position = Vector2(indexedPosition.x * grid.tileWidth, indexedPosition.y * grid.tileHeight);
		currentTile.SetPosition(position);

		if (grid.IsMouseInGrid())
		{
			if (Mouse::IsButtonPressed(Mouse::Button::Left))
			{
				int index = indexedPosition.x + (indexedPosition.y * grid.width);
				tileMap.AddSprite((Sprite(currentTile.GetTexture(), currentTile.GetPosition(), 0, BF::Math::Rectangle(0, 0, 64, 64), currentTile.GetColor())), index);
			}
		}
	}

	void PaintTile::Render()
	{
		spriteRenderer.Render(currentTile);
	}
}