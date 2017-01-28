#include "_2DScene.h"

namespace _2DScene
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	void DoButtonWork();

	_2DScene::_2DScene() :
		button(*this), font(spriteRenderer.GetShader())//, spriteAnimation(spriteRenderer, spriteRenderer.GetSpriteShader())
	{
		t = new Texture2D(spriteRenderer.GetShader());
		t2 = new Texture2D(spriteRenderer.GetShader());
	}

	_2DScene::~_2DScene()
	{
	}

	void _2DScene::Initialize()
	{
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		spriteRenderer.Initialize();
		//GetWidgetManager().Initialize();
	}

	void _2DScene::Load()
	{
		t->Load("Assets/Textures/tilea5.png");
		t2->Load("Assets/Textures/test2.png");

		sprite1 = Sprite(t, BF::Math::Vector3(0.0f, 0.0f, 0.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f));
		sprite2 = Sprite(t2, BF::Math::Vector3(400.0f, 0.0f, 0.0f), Vector4(1.0f));
		sprite3 = Sprite(t, BF::Math::Vector3(0.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite4 = Sprite(t, BF::Math::Vector3(400.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite5 = Sprite(t2, BF::Math::Vector3(800.0f, 500.0f, 0.0f), Vector4(1.0f));

		//fontAtlas = font.Load("", BF::Graphics::Fonts::Font::Language::English);
		//fontSprite = Sprite(fontAtlas->texture, BF::Math::Vector3(350.0f, 350.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f));
		
		//tileMap.Load("Assets/Maps/TileMap.bfm");

		//GetWidgetManager().Load();

		//spriteAnimation.Load("Assets/Animation/spriteAnimation.bfa");

		button.AddOnClickListener(DoButtonWork);
	}

	void _2DScene::FixedUpdate()
	{
		//BF_WARNING("TICKS");
		//spriteAnimation.Update();
	}

	void DoButtonWork()
	{
		BF_LOG_INFO("lol xD");
	}

	void _2DScene::Update()
	{
		//GetWidgetManager().Update();

		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToWindow().x, BF::Input::Mouse::GetPositionRelativeToWindow().y );
		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToScreen().x, BF::Input::Mouse::GetPositionRelativeToScreen().y);
	}

	void _2DScene::Render()
	{
		BF::Engine::GetContext().Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));
		//GetWidgetManager().Render();

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::None);
		spriteRenderer.Render(sprite1);
		spriteRenderer.Render(sprite2);
		//spriteRenderer.Draw(sprite3);
		//spriteRenderer.Draw(sprite4);
		//spriteRenderer.Render(fontSprite);
		//spriteRenderer.RenderText(*fontAtlas, "Blue Flame Engine !", BF::Math::Vector3(0.0f, 50.0f, 0.0f), BF::Math::Vector4(0.0f, 0.0f, 1.0f, 1.0f));
		//spriteRenderer.RenderText(*fontAtlas, "a b c d e f g h i j k l m n o p q r s t u v w x y z", BF::Math::Vector3(0.0f, 150.0f, 0.0f), BF::Math::Vector4(0.0f, 1.0f, 0.0f, 1.0f));
		//spriteRenderer.RenderText(*fontAtlas, "A B C D E F G H I J K L MNOPQRSTUVWXYZ", BF::Math::Vector3(0.0f, 250.0f, 0.0f), BF::Math::Vector4(1.0f, 0.0f, 0.0f, 1.0f));
		//spriteRenderer.Draw(sprite5);
		//spriteRenderer.DrawRectangle(BF::Math::Rectangle(1200, 800, 100, 100), BF::Math::Vector4(1.0, 0.0, 1.0, 1.0));

		//spriteAnimation.Render();
		spriteRenderer.End();

		//tileMap.Draw();

		BF::Engine::GetContext().SwapBuffers();
	}
}