#include "_3DScene.h"

namespace _3DScene
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;

	_3DScene::_3DScene(BF::Application::Window* window) :
		window(window), context(nullptr), shader(nullptr), model(nullptr), constentBuffer(nullptr), /*fpsCamera(nullptr),*/ initBuffer()
	{
		timer = new Timer();
		context = new Context(window, RenderAPI::OpenGL);
		shader = new Shader(context);

		constentBuffer = new ConstentBuffer(context, shader);
		model = new Model(context, shader);
		//fpsCamera = new FPSCamera(Matrix4::Perspective(90.0f, window->GetAspectRatio(), 1.0f, 12.0f));

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader->Load("Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("Assets/Shaders/GLSL/3D/VertexShader.glsl", "Assets/Shaders/GLSL/3D/PixelShader.glsl");

		//model->Load("Assets/A380.obj");
		//model->Load("Assets/Cube.obj_");
		model->Load("Assets/Models/MultiMeshAndTexturedCubes/MultiMeshAndTexturedCubes.obj");
#endif

#if BF_PLATFORM_LINUX
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");

		//texture2D->Load("projects/Sandbox-Linux/Sandbox/silver.png");
		//model->Load("projects/Sandbox-Linux/Sandbox/A380.obj");
#endif

		shader->Bind();
		constentBuffer->Create(sizeof(initBuffer), 0);
		context->SetPrimitiveType(PrimitiveType::TriangleList);

		initBuffer.viewMatrix = Matrix4::LookAt(Vector3(15.0f, 0, 0), Vector3(35.0f, 0.0f, 5.0f), Vector3(0, 1, 0));
		initBuffer.projectionMatrix = Matrix4::Perspective(90.0f, window->GetAspectRatio(), 0.1f, 1500.0f);
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Draw()
	{
		++frames;
		context->EnableDepthBuffer(true);
		//fpsCamera->Update();
		context->Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		angle += 0.050f;
		initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, 0.0f, 0.0f)) * Matrix4::Rotate(angle, Vector3(0, 0, 1)) * Matrix4::Scale(Vector3(2.0f, 2.0f, 2.0f));
		constentBuffer->Update(&initBuffer, sizeof(initBuffer));

		model->Draw();
		context->SwapBuffers();

		if (timer->GetElapsedTimeInSeconds() >= 1.0f)
		{
			std::cout << frames << std::endl;
			timer->Reset();
			frames = 0;
		}
	}

	void _3DScene::CleanUp()
	{
		shader->CleanUp();
		//context->CleanUp();
	}
}