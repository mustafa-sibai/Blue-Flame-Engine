#include "PaintTile.h"
#include <BF/Input/Mouse.h>
#include <BF/System/Log.h>

namespace Editor
{
	using namespace BF;
	using namespace BF::Math;
	using namespace BF::Input;
	using namespace BF::Graphics::Renderers;

	PaintTile::PaintTile(Grid& grid, Editor::TileMap& tileMap) :
		grid(grid), tileMap(tileMap)
	{
	}


	PaintTile::~PaintTile()
	{
	}

	void PaintTile::SetCurrentTile(Sprite currentTile)
	{
		this->currentTile = currentTile;
	}

	void PaintTile::Initialize(BF::Graphics::Renderers::SpriteRenderer& spriteRenderer)
	{
		this->spriteRenderer = &spriteRenderer;
	}

	void PaintTile::Update()
	{
		if (grid.IsMouseInGrid())
		{
			Vector2 indexedOffset = Vector2(floor(grid.GetRectangle().x / (float)grid.tileWidth), floor(grid.GetRectangle().y / (float)grid.tileHeight));
			Vector2 offset = Vector2(grid.GetRectangle().x - (indexedOffset.x * grid.tileWidth), grid.GetRectangle().y - (indexedOffset.y * grid.tileHeight));

			Vector2 indexedPosition = Vector2((int)((Mouse::GetPosition().x - offset.x) / grid.tileWidth), (int)((Mouse::GetPosition().y - offset.y) / grid.tileHeight));
			Vector2 position = Vector2((indexedPosition.x * grid.tileWidth) + offset.x, indexedPosition.y * (grid.tileHeight) + offset.y);
			currentTile.SetPosition(position);

			if (Mouse::IsButtonPressed(Mouse::Button::Left))
			{
				int index = indexedPosition.x + (indexedPosition.y * grid.GetRectangle().width);
				tileMap.AddSprite((Sprite(currentTile.GetTexture(), currentTile.GetPosition(), 0, BF::Math::Rectangle(0, 0, 64, 64), currentTile.GetColor())), index);
			}
		}
	}

	void PaintTile::Render()
	{
		spriteRenderer->Render(currentTile);
	}
}