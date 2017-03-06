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

	TileSheetPanel::TileSheetPanel(Scene& scene) :
		Panel(scene), rectangle(0, 0, 500, 1000), gridRectangle(rectangle.x, rectangle.y, 10, 10), texture(spriteRenderer->GetShader()), grid(gridRectangle)
	{
	}

	TileSheetPanel::~TileSheetPanel()
	{
	}

	void TileSheetPanel::Initialize(SpriteRenderer& spriteRenderer)
	{
		Panel::Initialize(spriteRenderer);
		grid.Initialize(spriteRenderer);
	}

	void TileSheetPanel::Load(const StyleSheet& StyleSheet, const string& widgetName)
	{
		Panel::Load(StyleSheet, widgetName);
		SetRectangle(rectangle);

		texture.Load("../Sandbox/Assets/Textures/tilea5.png");
		tilesheet = Sprite(&texture, Math::Vector2((float)rectangle.x, (float)rectangle.y), 0, Color(1.0f));

		SetContentRectangle(Math::Rectangle(rectangle.x, rectangle.y, texture.GetTextureData().width, texture.GetTextureData().height));
	}

	void TileSheetPanel::Update()
	{
		Panel::Update();
		tilesheet.SetPosition(GetContentPosition());
	}

	void TileSheetPanel::Render()
	{
		Panel::Render();
		grid.Render();
		spriteRenderer->Render(tilesheet);
		spriteRenderer->RenderRectangle(Math::Rectangle(Mouse::GetPosition().x, Mouse::GetPosition().y, 64, 64), Color(0.0f, 0.0f, 1.0f, 0.5f));
	}
}