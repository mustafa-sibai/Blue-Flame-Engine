#include "_3DScene2.h"

namespace _3DScene2
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;

	_3DScene2::_3DScene2() :
		cubeModel(shader), planeModel(shader), lightModel(lightShader), material(shader)
	{
	}

	_3DScene2::~_3DScene2()
	{
	}

	void _3DScene2::Initialize()
	{
		BF::Engine::GetContext().EnableDepthBuffer(true);
		//BF::Engine::GetContext().EnableVsync(true);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		fpsCamera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
		skybox.Initialize();

		constantBuffer.Create(sizeof(LightBuffer), 1);
		materialConstantBuffer.Create(sizeof(material.colorBuffer), 2);

		//terrain.Initialize();
	}

	void _3DScene2::Load()
	{
		//terrain.Load("Assets/HeightMaps/heightmap2.bmp");

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			lightShader.LoadFromFile("Assets/Shaders/HLSL/Compiled/Light/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/Light/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			lightShader.LoadFromFile("Assets/Shaders/GLSL/Light/VertexShader.glsl", "Assets/Shaders/GLSL/Light/PixelShader.glsl");
#elif defined(BF_PLATFORM_LINUX)
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			lightShader.LoadFromFile("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader.LoadFromFile("Assets/Shaders/HLSL/Compiled/3DMipAF/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3DMipAF/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.LoadFromFile("Assets/Shaders/GLSL/3DMipAF/VertexShader.glsl", "Assets/Shaders/GLSL/3DMipAF/PixelShader.glsl");
#elif defined(BF_PLATFORM_LINUX)
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.LoadFromFile("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

		shader.Bind();

		std::vector<std::string> filenames{ "Assets/TextureCubes/LancellottiChapel/posx.jpg", "Assets/TextureCubes/LancellottiChapel/negx.jpg",
											"Assets/TextureCubes/LancellottiChapel/posy.jpg", "Assets/TextureCubes/LancellottiChapel/negy.jpg",
											"Assets/TextureCubes/LancellottiChapel/posz.jpg", "Assets/TextureCubes/LancellottiChapel/negz.jpg" };

		skybox.Load(filenames);

		planeModel.Load("Assets/Models/Plane.bfx");
		cubeModel.Load("Assets/Models/Cube.bfx");
		lightModel.Load("Assets/Models/Cube.bfx");

		material.diffuseMap.Load("Assets/Textures/diffuseMap.png", Texture::Wrap::ClampToBorder, Texture::Filter::AnisotropicX16);
		material.specularMap.Load("Assets/Textures/specularMap.png", Texture::Wrap::ClampToBorder, Texture::Filter::AnisotropicX16);
	}

	/*void _3DScene2::FixedUpdate()
	{

	}*/

	void _3DScene2::Update()
	{
		angle += 0.5f;
		fpsCamera.Update();

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

	void _3DScene2::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		skybox.Render();

		shader.Bind();

		for (int z = 0; z < 10; z++)
		{
			for (int x = 0; x < 10; x++)
			{
				fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(20.0f * x, -2.5f, 20.0f * z)) * Matrix4::Rotate(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(10.0f)));
				planeModel.Render();
			}
		}

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, -1.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f)));

		//material.colorBuffer.ambientColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.diffuseColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);

		material.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		material.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		material.colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		material.colorBuffer.shininess = 32.0f;
		materialConstantBuffer.Update(&material, sizeof(material.colorBuffer));
		material.Bind();

		cubeModel.Render();

		shader.Unbind();

		lightShader.Bind();

		light.posDir = Vector4(9.0f, 20.0f, 0.0f, 1.0f);

		light.ambientColor	= Color(1.0f, 1.0f, 1.0f, 1.0f);
		light.diffuseColor	= Color(0.5f, 0.5f, 0.5f, 1.0f);
		light.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		constantBuffer.Update(&light, sizeof(LightBuffer));

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(light.posDir.x, light.posDir.y, light.posDir.z)) * Matrix4::Scale(Vector3(0.1f)));
		lightModel.Render();

		lightShader.Unbind();

		//terrain.Render();

		BF::Engine::GetContext().SwapBuffers();
	}
}