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
		cubeModel(shader), planeModel(shader), wallModel(shader), lightModel(lightShader), floorMaterial(shader), wallMaterial(shader)
	{
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Initialize()
	{
		BF::Engine::GetContext().EnableDepthBuffer(true);
		//BF::Engine::GetContext().EnableVsync(true);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		fpsCamera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
		skybox.Initialize();

		constentBuffer.Create(sizeof(LightBuffer), 1);
		materialConstentBuffer.Create(sizeof(floorMaterial.colorBuffer), 2);

		//terrain.Initialize();
	}

	void _3DScene::Load()
	{
		//terrain.Load("Assets/HeightMaps/heightmap2.bmp");

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			lightShader.Load("Assets/Shaders/HLSL/Compiled/Light/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/Light/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			lightShader.Load("Assets/Shaders/GLSL/Light/VertexShader.glsl", "Assets/Shaders/GLSL/Light/PixelShader.glsl");
#elif defined(BF_PLATFORM_LINUX)
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			lightShader.Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader.Load("Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.Load("Assets/Shaders/GLSL/3D/VertexShader.glsl", "Assets/Shaders/GLSL/3D/PixelShader.glsl");
#elif defined(BF_PLATFORM_LINUX)
		if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.Load("projects/Sandbox-Linux/Sandbox/VertexShader.glsl", "projects/Sandbox-Linux/Sandbox/FragmentShader.glsl");
#endif

		shader.Bind();

		std::vector<std::string> filenames{ "Assets/TextureCubes/LancellottiChapel/posx.jpg", "Assets/TextureCubes/LancellottiChapel/negx.jpg",
											"Assets/TextureCubes/LancellottiChapel/posy.jpg", "Assets/TextureCubes/LancellottiChapel/negy.jpg",
											"Assets/TextureCubes/LancellottiChapel/posz.jpg", "Assets/TextureCubes/LancellottiChapel/negz.jpg" };

		skybox.Load(filenames, "Assets/Shaders/GLSL/TextureCube/VertexShader.glsl", "Assets/Shaders/GLSL/TextureCube/PixelShader.glsl");

		planeModel.Load("Assets/Models/Plane.bfx");
		wallModel.Load("Assets/Models/Plane.bfx");
		cubeModel.Load("Assets/Models/Cube.bfx");
		lightModel.Load("Assets/Models/Cube.bfx");
		//, Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16
		floorMaterial.diffuseMap.Load("Assets/Textures/diffuseMap.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		floorMaterial.specularMap.Load("Assets/Textures/specularMap.png");
		floorMaterial.normalMap.Load("Assets/Textures/normalMap.jpg");

		wallMaterial.diffuseMap.Load("Assets/Textures/wall/brickwall.jpg", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		wallMaterial.specularMap.Load("Assets/Textures/wall/specularMap.jpg");
		wallMaterial.normalMap.Load("Assets/Textures/wall/brickwall_normal.jpg");

		light.position.w = 1.0f;
	}

	void _3DScene::FixedUpdate()
	{
		angle += 0.5f;
		fpsCamera.Update();
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


		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::F))
		{
			light.position.x++;
		}

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::G))
		{
			light.position.y++;
		}

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::H))
		{
			light.position.z++;
		}


		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::V))
		{
			light.position.x--;
		}

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::B))
		{
			light.position.y--;
		}

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::N))
		{
			light.position.z--;
		}
	}

	void _3DScene::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		skybox.Render();

		skybox.Bind();
		shader.Bind();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, -2.5f, 0.0f)) * Matrix4::Rotate(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(10.0f)));
		planeModel.Render();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, 15.0f, 10.0f)) * Matrix4::Rotate(90.0f, Vector3(1, 0, 0)) * Matrix4::Scale(Vector3(10.0f)));
		
		wallMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		wallMaterial.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		wallMaterial.colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		wallMaterial.colorBuffer.shininess = 32.0f;
		materialConstentBuffer.Update(&wallMaterial, sizeof(wallMaterial.colorBuffer));
		wallMaterial.Bind();
		wallModel.Render();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, -1.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f)));

		//material.colorBuffer.ambientColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.diffuseColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);

		floorMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.shininess = 32.0f;
		materialConstentBuffer.Update(&floorMaterial, sizeof(floorMaterial.colorBuffer));
		floorMaterial.Bind();

		cubeModel.Render();

		shader.Unbind();
		skybox.Unbind();

		lightShader.Bind();

		light.ambientColor	= Color(0.2f, 0.2f, 0.2f, 1.0f);
		light.diffuseColor	= Color(1.0f, 0.0f, 0.0f, 1.0f);
		light.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		constentBuffer.Update(&light, sizeof(LightBuffer));

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(light.position.x, light.position.y, light.position.z)) * Matrix4::Scale(Vector3(0.1f)));
		lightModel.Render();

		lightShader.Unbind();

		//terrain.Render();

		BF::Engine::GetContext().SwapBuffers();
	}
}