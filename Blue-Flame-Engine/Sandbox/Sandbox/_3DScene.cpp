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
		window(window), context(nullptr), shader(nullptr), model(nullptr), constentBuffer(nullptr), fpsCamera(nullptr), initBuffer()
	{
		timer = new Timer();
		context = new Context(window, RenderAPI::OpenGL);
		shader = new Shader(context);

		constentBuffer = new ConstentBuffer(context, shader);
		model = new Model(context, shader);
		fpsCamera = new FPSCamera(Matrix4::Perspective(45.0f, window->GetAspectRatio(), 0.1f, 1500.0f));

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader->Load("Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader->Load("Assets/Shaders/GLSL/3D/VertexShader.glsl", "Assets/Shaders/GLSL/3D/PixelShader.glsl");

		//model->Load("Assets/Models/crytek-sponza/sponza.obj");
		//model->Load("Assets/Models/crytek-sponza/test.obj");
		//model->Load("Assets/Models/crytek-sponza/untitled.fbx");
		//model->Load("Assets/Models/crytek-sponza/sponza.fbx");
		//model->Load("Assets/Models/Cube/Cube.fbx");
		//model->Load("Assets/Models/sphere/smooth.fbx");
		//model->Load("Assets/Models/sphere/flat.fbx");
		//model->Load("Assets/Models/TexturedCube/TexturedCube.fbx");
		//model->Load("Assets/Models/MultiTextureCube/MultiTextureCube.fbx");
		//model->Load("Assets/Models/MultiTextureCube/untitled.fbx");
		
		//model->Load("Assets/Models/untitled.obj");
		//model->Load("Assets/Models/MultiMeshAndTexturedCubes/MultiMeshAndTexturedCubes.obj");
		model->Load("Assets/Models/untitled.bfx");
		
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

		initBuffer.projectionMatrix = fpsCamera->GetProjectionMatrix();
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Draw()
	{
		++frames;
		context->EnableDepthBuffer(true);
		fpsCamera->Update();

		context->Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		angle = -90.0f;
		initBuffer.viewMatrix = fpsCamera->GetViewMatrix();
		initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, 0.0f, 0.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));
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