#include "_2DScene.h"

namespace _2DScene
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;

	_2DScene::_2DScene(BF::Application::Window* window) :
		window(window), context(nullptr), shader(nullptr), spriteRenderer(nullptr), constentBuffer(nullptr)
	{
		timer = new Timer();
		context = new Context(window, RenderAPI::OpenGL);
		shader = new Shader(context);

		constentBuffer = new ConstentBuffer(context, shader);

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader->Load("Assets/Shaders/HLSL/Compiled/SpriteRenderer/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/SpriteRenderer/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("Assets/Shaders/GLSL/SpriteRenderer/VertexShader.glsl", "Assets/Shaders/GLSL/SpriteRenderer/PixelShader.glsl");
#endif

#if BF_PLATFORM_LINUX
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

		//shader->Bind();

		spriteRenderer = new SpriteRenderer(context, shader);

		constentBuffer->Create(sizeof(initBuffer), 0);

		context->SetPrimitiveType(PrimitiveType::TriangleList);

		t = new Texture2D(context, shader);
		t2 = new Texture2D(context, shader);
		t->Load("Assets/Textures/tilea5.png");
		t2->Load("Assets/Textures/test2.png");

		font = new Font(context, shader);

		//sprites = new std::vector<BF::Graphics::Renderers::Sprite*>();

		//for (size_t y = 0; y < 160; y++)
			//for (size_t x = 0; x < 300; x++)

		//sprites->push_back(new Sprite(t, BF::Math::Vector3(500.0f, 200.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		//sprites->push_back(new Sprite(t2, BF::Math::Vector3(350.0f, 200.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));

		initBuffer.modelMatrix = Matrix4::Identity();
		initBuffer.viewMatrix = Matrix4::Identity();
		initBuffer.projectionMatrix = Matrix4::Orthographic(0.0f, window->GetClientWidth(), 0.0f, window->GetClientHeight(), -1.0f, 1.0f);

		float r = 99.0215;
		BF_INFO("BF_INFO %f", r);
		BF_WARNING("BF_WARNING %f", r);
		BF_ERROR("BF_ERROR  %f", r);
		BF_FATAL("BF_FATAL %f", r);
	}

	_2DScene::~_2DScene()
	{
	}

	void _2DScene::Draw()
	{
		++frames;

		context->Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		constentBuffer->Update(&initBuffer, sizeof(initBuffer));

		spriteRenderer->Begin(SpriteRenderer::SubmitType::DynamicSubmit);
		spriteRenderer->Submit(new Sprite(t, BF::Math::Vector3(0.0f, 0.0f, 0.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f)));
		spriteRenderer->Submit(new Sprite(t2, BF::Math::Vector3(300.0f, 0.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		spriteRenderer->Submit(new Sprite(t2, BF::Math::Vector3(600.0f, 0.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		spriteRenderer->Submit(new Sprite(font->texture, BF::Math::Vector3(350.0f, 200.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		spriteRenderer->Submit(new Sprite(t2, BF::Math::Vector3(0.0f, 800.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		spriteRenderer->Submit(new Sprite(t, BF::Math::Vector3(500.0f, 800.0f, 0.0f), Vector4(1.0f, 1.0f, 1.0f, 1.0f)));
		spriteRenderer->End();

		context->SwapBuffers();

		if (timer->GetElapsedTimeInSeconds() >= 1.0f)
		{
			std::cout << frames << std::endl;
			timer->Reset();
			frames = 0;
		}
	}

	void _2DScene::CleanUp()
	{
		shader->CleanUp();
		//context->CleanUp();
	}
}