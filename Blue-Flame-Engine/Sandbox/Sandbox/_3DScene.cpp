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
		fpsCamera(nullptr), initBuffer(), cubeModel(shader), planeModel(shader), constentBuffer(shader)
	{
		fpsCamera = new FPSCamera(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Initialize()
	{
		BF::Engine::GetContext().EnableDepthBuffer(true);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		fpsCamera->Initialize();
		initBuffer.projectionMatrix = fpsCamera->GetProjectionMatrix();

		skybox.Initialize();
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
		shader.Bind();

		std::vector<std::string> filenames{ "Assets/TextureCubes/LancellottiChapel/posx.jpg", "Assets/TextureCubes/LancellottiChapel/negx.jpg",
											"Assets/TextureCubes/LancellottiChapel/posy.jpg", "Assets/TextureCubes/LancellottiChapel/negy.jpg",
											"Assets/TextureCubes/LancellottiChapel/posz.jpg", "Assets/TextureCubes/LancellottiChapel/negz.jpg" };

		skybox.Load(filenames, "Assets/Shaders/GLSL/TextureCube/VertexShader.glsl", "Assets/Shaders/GLSL/TextureCube/PixelShader.glsl");
		
		//model->Load("Assets/Models/untitled.bfx");
		planeModel.Load("Assets/Models/Plane.bfx");
		cubeModel.Load("Assets/Models/Cube.bfx");
		
		constentBuffer.Create(sizeof(initBuffer), 0);
	}

	void _3DScene::FixedUpdate()
	{
		fpsCamera->Update();
		initBuffer.viewMatrix = fpsCamera->GetViewMatrix();
		initBuffer.cameraPosition = Vector4(fpsCamera->GetPosition().x, fpsCamera->GetPosition().y, fpsCamera->GetPosition().z, 1.0f);
		angle += 0.5f;
	}

	void _3DScene::Update()
	{
		if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::A))
			BF_LOG_INFO("A Pressed !");

		if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::B))
			BF_LOG_INFO("B Pressed !");

		if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::X))
			BF_LOG_INFO("X Pressed !");

		if (BF::Input::Controllers::Primary().IsButtonPressed(BF::Input::Controller::Button::Y))
			BF_LOG_INFO("Y Pressed !");

		//---------------------------------------------------------

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Up))
			BF_LOG_INFO("Up Pressed !");

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Down))
			BF_LOG_INFO("Down Pressed !");

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Left))
			BF_LOG_INFO("Left Pressed !");

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Right))
			BF_LOG_INFO("Right Pressed !");

		//---------------------------------------------------------

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Start))
			BF_LOG_INFO("Start Pressed !");

		if (BF::Input::Controllers::Secondary().IsButtonPressed(BF::Input::Controller::Button::Back))
			BF_LOG_INFO("Back Pressed !");
	}

	void _3DScene::Render()
	{
		BF::Engine::GetContext().Clear(Vector4(0.5, 0.0f, 0.0f, 1.0f));

		constentBuffer.Update(&initBuffer, sizeof(initBuffer));
		skybox.Render();

		shader.Bind();

		initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, -2.5f, 0.0f)) * Matrix4::Rotate(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(10.0f));
		constentBuffer.Update(&initBuffer, sizeof(initBuffer));
		planeModel.Draw();
		
		initBuffer.modelMatrix = Matrix4::Translate(Vector3(0.0f, -1.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f));
		constentBuffer.Update(&initBuffer, sizeof(initBuffer));
		cubeModel.Draw();

		shader.Unbind();

		BF::Engine::GetContext().SwapBuffers();
	}
}