#include "TileSheetPanel.h"

namespace Editor
{
	using namespace std;
	using namespace BF;
	using namespace BF::Graphics;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Graphics::API;
	using namespace BF::Application;
	using namespace BF::Math;
	using namespace BF::Input;

	TileSheetPanel::TileSheetPanel(Scene& scene, PaintTile& paintTile) :
		Panel(scene), paintTile(paintTile), rectangle(0, 0, 500, 1000), gridRectangle(rectangle.x, rectangle.y, 10, 10), texture(spriteRenderer->GetShader()), grid(gridRectangle)
	{
	}

	TileSheetPanel::~TileSheetPanel()
	{
	}

	void TileSheetPanel::Initialize(SpriteRenderer& spriteRenderer, int zLayer)
	{
		Panel::Initialize(spriteRenderer, zLayer);
		grid.Initialize(spriteRenderer);
	}

	void TileSheetPanel::Load(const StyleSheet& StyleSheet, const string& widgetName)
	{
		Panel::Load(StyleSheet, widgetName);
		SetRectangle(rectangle);

		texture.Load("../Sandbox/Assets/Textures/tilea5.png");
		tilesheet = Sprite(&texture, Math::Vector2((float)rectangle.x, (float)rectangle.y), 0, Color(1.0f));

		SetContentRectangle(Math::Rectangle(rectangle.x, rectangle.y, texture.GetTextureData()->width, texture.GetTextureData()->height));
	}

	void TileSheetPanel::Update()
	{
		Panel::Update();
		tilesheet.SetPosition(GetContentPosition());

		if (grid.IsMouseInGrid())
		{
			Vector2 indexedOffset = Vector2(floor(grid.GetRectangle().x / (float)grid.tileWidth), floor(grid.GetRectangle().y / (float)grid.tileHeight));
			Vector2 offset = Vector2(grid.GetRectangle().x - (indexedOffset.x * grid.tileWidth), grid.GetRectangle().y - (indexedOffset.y * grid.tileHeight));

			Vector2 indexedPosition = Vector2((int)((Mouse::GetPosition().x - offset.x) / grid.tileWidth), (int)((Mouse::GetPosition().y - offset.y) / grid.tileHeight));
			Vector2 position = Vector2((indexedPosition.x * grid.tileWidth) + offset.x, indexedPosition.y * (grid.tileHeight) + offset.y);
			highlighter = RegularPolygon(Math::Rectangle(position.x, position.y, 64, 64), 0, Color(0.2f, 0.2f, 0.75f, 0.75f));

			if (Mouse::IsButtonPressed(Mouse::Button::Left))
			{
				paintTile.SetCurrentTile(Sprite(&texture, Math::Rectangle(position.x, position.y, 64, 64), 0, Math::Rectangle(position.x, position.y, 64, 64), Color(1.0f, 1.0f, 1.0f, 1.0f)));
			}
		}
	}

	void TileSheetPanel::Render()
	{
		Panel::Render();
		spriteRenderer->Render(tilesheet);
		spriteRenderer->Render(highlighter);
		grid.Render();
	}
}