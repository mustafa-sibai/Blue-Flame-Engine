#include "_2DScene.h"

namespace _2DScene
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

	void DoButtonWork();
	
	bool _2DScene::TimeFunction(void* this_pointer)
	{
		_2DScene* self = static_cast<_2DScene*>(this_pointer);
		if (self->timer.GetElapsedTimeInSeconds() > 5)
		{
			self->timer.Reset();
			return true;
		}
		else
			return false;
	}

	_2DScene::_2DScene() :
		button(*this), checkbox(*this), panel(*this), font(spriteRenderer.GetShader()), waypoint(sprite1, waypoints)/*, renderTarget(spriteRenderer.GetShader())*/ //, spriteAnimation(spriteRenderer, spriteRenderer.GetSpriteShader())
	{
		t = new Texture2D(spriteRenderer.GetShader());
		t2 = new Texture2D(spriteRenderer.GetShader());
		t3 = new Texture2D(spriteRenderer.GetShader());
		t4 = new Texture2D(spriteRenderer.GetShader());
	}

	_2DScene::~_2DScene()
	{
	}

	void _2DScene::Initialize()
	{
		//Scene::Initialize();

		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		spriteRenderer.Initialize();
	}

	void _2DScene::Load()
	{
		//Scene::Load();

		t->Load("Assets/Textures/tilea5.png");
		t2->Load("Assets/Textures/test2.png");
		t3->Load("Assets/Textures/Untitled.png");
		t4->Load("Assets/Textures/silver.png");

		sprite1 = Sprite(t, Vector2(0.0f, 0.0f), 0, Color(1.0f, 1.0f, 1.0f, 1.0f));
		sprite2 = Sprite(t, Vector2(100.0f, 100.0f), 0, BF::Math::Rectangle(32, 0, 32, 32), Color(1.0f));
		sprite3 = Sprite(t, Vector2(300.0f, 100.0f), 0, BF::Math::Rectangle(64, 0, 32, 32), Color(1.0f));
		sprite4 = Sprite(t, Vector2(300.0f, 300.0f), 0, BF::Math::Rectangle(96, 0, 32, 32), Color(1.0f));
		sprite5 = Sprite(t, Vector2(100.0f, 300.0f), 0, BF::Math::Rectangle(128, 0, 32, 32), Color(1.0f));

		sprite6 = Sprite(t2, Vector2(800.0f, 0.0f), 0, Color(1.0f));
		sprite7 = Sprite(t4, BF::Math::Rectangle(0, 0, 1920, 1080), 0, Color(1.0f));
		sprite8 = Sprite(t3, BF::Math::Rectangle(0, 0, 1920, 1080), 0, Color(1.0f));

		node = Waypoint::Node(Vector2(100.0f, 100.0f));
		node2 = Waypoint::Node(Vector2(300.0f, 100.0f));

		line = LineShape(Vector2(0.0f, 100.0f), Vector2(800.0f, 100.0f), 5, 0, Color(0.0f, 0.0f, 1.0f, 1.0f));
		line2 = LineShape(Vector2(0.0f, 300.0f), Vector2(800.0f, 300.0f), 5, 0, Color(1.0f, 0.0f, 0.0f, 1.0f));

		rp = RegularPolygon(Math::Rectangle(225, 200, 64, 64), 0, Color(0.0f, 0.0f, 1.0f, 1.0f));
		rp2 = RegularPolygon(Math::Rectangle(225, 400, 64, 64), 0, Color(1.0f, 0.0f, 0.0f, 1.0f));

		//waypoints.push_back(Waypoint::Node(Vector2(100.0f, 100.0f), TimeFunction));
		//waypoints.push_back(Waypoint::Node(Vector2(300.0f, 100.0f), TimeFunction));
		//waypoints.push_back(Waypoint::Node(Vector2(300.0f, 300.0f), TimeFunction));
		//waypoints.push_back(Waypoint::Node(Vector2(100.0f, 300.0f), TimeFunction));

		//fontAtlas = font.Load("", BF::Graphics::Fonts::Font::Language::English);
		//fontSprite = Sprite(fontAtlas->texture, BF::Math::Vector3(350.0f, 350.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f));

		//tileMap.Load("Assets/Maps/TileMap.bfm");
		//spriteAnimation.Load("Assets/Animation/spriteAnimation.bfa");

		//button.AddOnClickListener(DoButtonWork);

		button.SetPosition(Vector2(100, 100));

		//renderTarget.Create(800, 600, Texture::Format::R8G8B8, Texture::TextureWrap::ClampToBorder, Texture::TextureFilter::Neatest);
	}

	void _2DScene::FixedUpdate()
	{
		//Scene::FixedUpdate();

		//BF_WARNING("TICKS");
		//spriteAnimation.Update();
	}

	void DoButtonWork()
	{
		BF_LOG_INFO("lol xD");
	}

	void _2DScene::Update()
	{
		//This is temporary.
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		//Scene::Update();
		camera.Update();
		//waypoint.Update();

		/*waypoint.GoTo(node);

		if(node.HasArrived())
			waypoint.GoTo(node2);*/

		/*if (checkbox.IsChecked())
			BF_LOG_ERROR("CHECKED !!");
		else
			BF_LOG_WARNING("NOT CHECKED !! ");*/

		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToWindow().x, BF::Input::Mouse::GetPositionRelativeToWindow().y );
		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToScreen().x, BF::Input::Mouse::GetPositionRelativeToScreen().y);
	}

	void _2DScene::Render()
	{
		//renderTarget.Bind();
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));
		//Scene::Render();

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::None);
		spriteRenderer.Render(line);
		spriteRenderer.Render(rp);
		spriteRenderer.Render(sprite1);
		spriteRenderer.Render(line2);
		spriteRenderer.Render(rp2);
		//spriteRenderer.RenderLine(Vector2(0.0f, 300.0f), Vector2(800.0f, 300.0f), 5, Color(1.0f, 0.0f, 0.0f, 1.0f));



		//spriteRenderer.SetScissor(Math::Rectangle(25, 50, 125, 200));
		//spriteRenderer.SetScissor(Math::Rectangle(0, 100, Engine::GetWindow().GetClientWidth(), Engine::GetWindow().GetClientHeight() - 200));
		//spriteRenderer.Render(sprite8);
		//spriteRenderer.SetScissor(Math::Rectangle(0, 0, 1920, 1080));

		//spriteRenderer.End();
		//spriteRenderer.SetScissor(Math::Rectangle(0, 0, 1920, 1080));

		//spriteRenderer.SetScissor(Math::Rectangle(0, 0, 1920, 1080));
		//spriteRenderer.EndScissor();

		//BF::Engine::GetContext().EnableScissor(false);

		/*spriteRenderer.Render(sprite2);
		spriteRenderer.Render(sprite3);
		spriteRenderer.Render(sprite4);
		spriteRenderer.Render(sprite5);
		spriteRenderer.Render(sprite1);*/

		
		//spriteRenderer.Render(sprite6);
		

		//spriteRenderer.RenderLine(Vector2(100.0f, 100.0f), Vector2(200.0f, 100.0f), 5, Vector4(0.0f, 0.0f, 1.0f, 1.0f));						  
		//spriteRenderer.RenderLine(Vector2(100.0f, 400.0f), Vector2(200.0f, 600.0f), 10, Vector4(0.0f, 0.0f, 1.0f, 1.0f));

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
		//renderTarget.Unbind();



		/*
		BF::Engine::GetContext().Clear(Color(0.0, 0.0f, 0.5f, 1.0f));

		Scene::Render();

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit, SpriteRenderer::SortingOrder::None);
		spriteRenderer.Render(Sprite(&renderTarget.GetTexture2D(), Vector2(700, 0), 0, Color(1.0f)));
		spriteRenderer.End();
		*/
		BF::Engine::GetContext().SwapBuffers();
	}
}