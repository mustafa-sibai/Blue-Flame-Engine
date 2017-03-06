#include "ScenePanel.h"

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

	ScenePanel::ScenePanel(Scene& scene, TileSheetPanel& tileSheetPanel) :
		tileSheetPanel(tileSheetPanel), grid(Math::Rectangle((int)position.x, (int)position.y, 10, 10)), paintTile(grid, tilemap), Panel(scene), position(750.0f, 0.0f)
	{
	}

	ScenePanel::~ScenePanel()
	{
	}

	void ScenePanel::Initialize(SpriteRenderer& spriteRenderer)
	{
		Panel::Initialize(spriteRenderer);
		paintTile.Initialize(spriteRenderer);
		grid.Initialize(spriteRenderer);
		tilemap.Initialize();
	}

	void ScenePanel::Load(const StyleSheet& StyleSheet, const string& widgetName)
	{
		Panel::Load(StyleSheet, widgetName);
		paintTile.SetCurrentTile(Sprite(&tileSheetPanel.texture, Vector2(0.0f, 0.0f), 0, Math::Rectangle(0, 0, grid.tileWidth, grid.tileHeight), Color(1.0f)));
		SetRectangle(Math::Rectangle((int)position.x, (int)position.y, 1130, 1010));
		//SetContentRectangle(Math::Rectangle((int)position.x, (int)position.y, texture.GetTextureData().width, texture.GetTextureData().height));
	}

	void ScenePanel::Update()
	{
		Panel::Update();
		paintTile.Update();
	}

	void ScenePanel::Render()
	{
		Panel::Render();
		grid.Render();
		paintTile.Render();
	}

	void ScenePanel::RenderTileMap()
	{
		tilemap.Render();
	}
}