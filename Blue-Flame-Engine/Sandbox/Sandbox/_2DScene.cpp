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
		constentBuffer(nullptr), spriteRenderer(shader), button(spriteRenderer)
	{
		constentBuffer = new ConstentBuffer(shader);
		font = new Font(shader);
		t = new Texture2D(shader);
		t2 = new Texture2D(shader);
		styleSheet = StyleSheet(shader);
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

		styleSheet.Load("Assets/GUI/StyleSheet.xml");

		t->Load("Assets/Textures/tilea5.png");
		t2->Load("Assets/Textures/test2.png");

		sprite1 = Sprite(t,  BF::Math::Vector3(0.0f,   0.0f, 0.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f));
		sprite2 = Sprite(t2, BF::Math::Vector3(400.0f, 0.0f, 0.0f), Vector4(1.0f));
		sprite3 = Sprite(t,  BF::Math::Vector3(0.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite4 = Sprite(t,  BF::Math::Vector3(400.0f, 500.0f, 0.0f), Vector4(1.0f));
		sprite5 = Sprite(t2, BF::Math::Vector3(800.0f, 500.0f, 0.0f), Vector4(1.0f));

		fontSprite = Sprite(font->texture, BF::Math::Vector3(350.0f, 200.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f));

		spriteRenderer.Initialize();
		constentBuffer->Create(sizeof(initBuffer), 0);
		button.Load(styleSheet);
	}

	void _2DScene::FixedUpdate()
	{
		//BF_WARNING("TICKS");
	}

	void _2DScene::Update()
	{
	}

	void _2DScene::Render()
	{
		Engine::GetContext().Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		constentBuffer->Update(&initBuffer, sizeof(initBuffer));

		spriteRenderer.Begin(SpriteRenderer::SubmitType::DynamicSubmit);
		spriteRenderer.Submit(sprite1);
		spriteRenderer.Submit(sprite2);
		spriteRenderer.Submit(sprite3);
		spriteRenderer.Submit(sprite4);
		spriteRenderer.Submit(fontSprite);
		spriteRenderer.Submit(sprite5);
		button.Render();
		spriteRenderer.End();

		Engine::GetContext().SwapBuffers();
	}
}