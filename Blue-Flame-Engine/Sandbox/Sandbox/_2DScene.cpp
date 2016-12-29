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

	_2DScene::_2DScene() :
		constentBuffer(nullptr), spriteRenderer(shader), button(*this), font(shader), spriteAnimation(spriteRenderer, shader)
	{
		constentBuffer = new ConstentBuffer(shader);
		t = new Texture2D(shader);
		t2 = new Texture2D(shader);
	}

	_2DScene::~_2DScene()
	{
	}

	void _2DScene::Initialize()
	{
		initBuffer.modelMatrix = Matrix4::Identity();
		initBuffer.viewMatrix = Matrix4::Identity();
		initBuffer.projectionMatrix = Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f);

		Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		GetWidgetManager().Initialize();
	}

	void _2DScene::Load()
	{
#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader.Load("Assets/Shaders/HLSL/Compiled/SpriteRenderer/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/SpriteRenderer/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.Load("Assets/Shaders/GLSL/SpriteRenderer/VertexShader.glsl", "Assets/Shaders/GLSL/SpriteRenderer/PixelShader.glsl");
#elif BF_PLATFORM_LINUX
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

		t->Load("Assets/Textures/tilea5.png");
		t2->Load("Assets/Textures/test2.png");

		sprite1 = Sprite(t,  BF::Math::Vector3(0.0f,   0.0f, 0.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f));
		sprite2 = Sprite(t2, BF::Math::Vector3(400.0f, 0.0f, 0.0f), Vector4(1.0f));
		sprite3 = Sprite(t,  BF::Math::Vector3(0.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite4 = Sprite(t,  BF::Math::Vector3(400.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite5 = Sprite(t2, BF::Math::Vector3(800.0f, 500.0f, 0.0f), Vector4(1.0f));

		fontAtlas = font.Load("", BF::Graphics::Fonts::Font::Language::English);
		fontSprite = Sprite(fontAtlas->texture, BF::Math::Vector3(350.0f, 350.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f));
		
		tileMap.Load("Assets/Maps/TileMap.bfm");

		spriteRenderer.Initialize();
		constentBuffer->Create(sizeof(initBuffer), 0);
		
		GetWidgetManager().Load();

		spriteAnimation.Load("Assets/Animation/spriteAnimation.bfa");
	}

	void _2DScene::FixedUpdate()
	{
		//BF_WARNING("TICKS");
		spriteAnimation.Update();
	}

	void _2DScene::Update()
	{
		GetWidgetManager().Update();

		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToWindow().x, BF::Input::Mouse::GetPositionRelativeToWindow().y );
		//BF_LOG_INFO("%f %f", BF::Input::Mouse::GetPositionRelativeToScreen().x, BF::Input::Mouse::GetPositionRelativeToScreen().y);

		if (button.IsReleased())
			BF_LOG_INFO("LOL");
	}

	void _2DScene::Render()
	{
		Engine::GetContext().Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		constentBuffer->Update(&initBuffer, sizeof(initBuffer));
		GetWidgetManager().Render();
		
		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit);
		//spriteRenderer.Draw(sprite1);
		//spriteRenderer.Draw(sprite2);
		//spriteRenderer.Draw(sprite3);
		//spriteRenderer.Draw(sprite4);
		spriteRenderer.Render(fontSprite);
		spriteRenderer.RenderText(*fontAtlas, "Blue Flame Engine !", BF::Math::Vector3(0.0f, 50.0f, 0.0f), BF::Math::Vector4(1.0f));
		spriteRenderer.RenderText(*fontAtlas, "a b c d e f g h i j k l m n o p q r s t u v w x y z", BF::Math::Vector3(0.0f, 150.0f, 0.0f), BF::Math::Vector4(1.0f));
		spriteRenderer.RenderText(*fontAtlas, "A B C D E F G H I J K L MNOPQRSTUVWXYZ", BF::Math::Vector3(0.0f, 250.0f, 0.0f), BF::Math::Vector4(1.0f));
		//spriteRenderer.Draw(sprite5);
		//spriteRenderer.DrawRectangle(BF::Math::Rectangle(1200, 800, 100, 100), BF::Math::Vector4(1.0, 0.0, 1.0, 1.0));

		spriteAnimation.Render();
		spriteRenderer.End();
		

		tileMap.Draw();

		Engine::GetContext().SwapBuffers();
	}
}