#include "GUIScene.h"


namespace GUIScene
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	GUIScene::GUIScene()
	{
	}

	GUIScene::~GUIScene()
	{
	}

	void GUIScene::Initialize()
	{
		Scene::Initialize();

		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		spriteRenderer.Initialize();

		//button.SetRectangle(BF::Math::Rectangle(700, 100, 300, 300));
		//button.SetZLayer(0);

	}

	void GUIScene::Load()
	{
		Scene::Load();
		
		s = BF::Graphics::Renderers::RegularPolygon(BF::Math::Rectangle(200, 0, 400, 200), 0, BF::Graphics::Color(0.2f, 0.0f, 1.0f, 1.0f));

		t.Load("Assets/Textures/tilea5.png");

		font.Load("Assets/Fonts/arial.ttf", 30, BF::Graphics::Fonts::FontAtlasFactory::Language::English);
		font2.Load("Assets/Fonts/consola.ttf", 20, BF::Graphics::Fonts::FontAtlasFactory::Language::English);
		text = Text(&font, "Blue Flame Engine !", Math::Rectangle(100, 0, 400, 200), Text::TextAlignment::MiddleCenter, 1, Color(1.0f, 1.0f, 1.0f, 1.0f));
		text2 = Text(&font2, "WTF", Math::Rectangle(50, 100, 400, 200), Text::TextAlignment::MiddleCenter, 1, Color(1.0f, 1.0f, 1.0f, 1.0f));

		ss = Sprite(&t, Vector2f(400, 0), 0, Color(1.0f));

		//text.SetTextAlignment(Text::TextAlignment::TopCenter);
		text.SetRectangle(Math::Rectangle(50, 0, 0, 0));
		text.SetFont(&font2);
		//text.SetText("WTF man. please work !");
		//text.SetTextAlignment(Text::TextAlignment::BottomRight);
	}

	void GUIScene::Update()
	{
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		Scene::Update();
		camera.Update();
	}

	void GUIScene::Render()
	{
		//(230, 25, 75)
		BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		Scene::Render();
		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::BackToFront);
		spriteRenderer.Render(ss);
		spriteRenderer.Render(text);
		spriteRenderer.Render(text2);
		spriteRenderer.End();
		BF::Engine::GetContext().SwapBuffers();
	}
}
