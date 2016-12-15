#include "_3DScene.h"

namespace _3DScene
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;

	_3DScene::_3DScene() :
		model(nullptr), constentBuffer(nullptr), fpsCamera(nullptr), initBuffer()
	{
		constentBuffer = new ConstentBuffer(shader);
		model = new Model(shader);
		fpsCamera = new FPSCamera(Matrix4::Perspective(45.0f, Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Initialize()
	{
		Engine::GetContext().EnableDepthBuffer(true);
		Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		initBuffer.projectionMatrix = fpsCamera->GetProjectionMatrix();
		angle = -90.0f;
		initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, 0.0f, 0.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));
	}

	void _3DScene::Load()
	{
#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader.Load("Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.Load("Assets/Shaders/GLSL/3D/VertexShader.glsl", "Assets/Shaders/GLSL/3D/PixelShader.glsl");
#elif BF_PLATFORM_LINUX
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

		model->Load("Assets/Models/untitled.bfx");

		shader.Bind();
		constentBuffer->Create(sizeof(initBuffer), 0);
	}

	void _3DScene::FixedUpdate()
	{
		fpsCamera->Update();
		//BF_WARNING("TICKS");
	}

	void _3DScene::Update()
	{
	}

	void _3DScene::Render()
	{
		Engine::GetContext().Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		initBuffer.viewMatrix = fpsCamera->GetViewMatrix();
		constentBuffer->Update(&initBuffer, sizeof(initBuffer));

		model->Draw();
		Engine::GetContext().SwapBuffers();
	}
}