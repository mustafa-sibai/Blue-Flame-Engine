#include "_3DScene.h"

namespace _3DScene
{
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Input;

	_3DScene::_3DScene() :
		cubeModel(shader), planeModel(shader), wallModel(shader), lightModel(lightShader), floorMaterial(shader), wallMaterial(shader), directionalLight(false)
	{
	}

	_3DScene::~_3DScene()
	{
	}

	void _3DScene::Initialize()
	{
		BF::Engine::GetContext().EnableDepthBuffer(true);
		//BF::Engine::GetContext().EnableVsync(true);
		BF::Engine::LimitFrameRate(60.0f);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		fpsCamera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));
		skybox.Initialize();

		constantBuffer.Create(sizeof(LightBuffer), 1);
		materialConstantBuffer.Create(sizeof(floorMaterial.colorBuffer), 2);

		//terrain.Initialize();
	}

	void _3DScene::Load()
	{
		//terrain.Load("Assets/HeightMaps/heightmap2.bmp");

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			lightShader.LoadFromFile("Assets/Shaders/HLSL/Compiled/Light/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/Light/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			lightShader.LoadStandardShader(ShaderType::Light);
#endif

#if BF_PLATFORM_WINDOWS
		if (Context::GetRenderAPI() == RenderAPI::DirectX)
			shader.LoadFromFile("Assets/Shaders/HLSL/Compiled/3D/VertexShader.cso", "Assets/Shaders/HLSL/Compiled/3D/PixelShader.cso");
		else if (Context::GetRenderAPI() == RenderAPI::OpenGL)
			shader.LoadStandardShader(ShaderType::_3D);
#endif

		shader.Bind();

		std::vector<std::string> filenames{ "Assets/TextureCubes/LancellottiChapel/posx.jpg", "Assets/TextureCubes/LancellottiChapel/negx.jpg",
											"Assets/TextureCubes/LancellottiChapel/posy.jpg", "Assets/TextureCubes/LancellottiChapel/negy.jpg",
											"Assets/TextureCubes/LancellottiChapel/posz.jpg", "Assets/TextureCubes/LancellottiChapel/negz.jpg" };

		skybox.Load(filenames);

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

		light.posDir.w = 1.0f;
	}

	/*void _3DScene::FixedUpdate()
	{

	}*/

	void _3DScene::Update()
	{
		angle += 0.1f * BF::Engine::GetDeltaTime();
		fpsCamera.Update();

		//BF_LOG_INFO("%f, %f, %f", fpsCamera.GetPosition().x, fpsCamera.GetPosition().y, fpsCamera.GetPosition().z);

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::U))
			directionalLight = true;

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::O))
			directionalLight = false;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::L))
			light.posDir.x++;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::J))
			light.posDir.x--;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::P))
			light.posDir.y++;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::Semicolon))
			light.posDir.y--;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::I))
			light.posDir.z++;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::K))
			light.posDir.z--;

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
		materialConstantBuffer.Update(&wallMaterial, sizeof(wallMaterial.colorBuffer));
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
		materialConstantBuffer.Update(&floorMaterial, sizeof(floorMaterial.colorBuffer));
		floorMaterial.Bind();

		cubeModel.Render();

		shader.Unbind();
		skybox.Unbind();

		lightShader.Bind();

		light.ambientColor = Color(0.2f, 0.2f, 0.2f, 1.0f);
		light.diffuseColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		light.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		constantBuffer.Update(&light, sizeof(LightBuffer));

		if (directionalLight)
			fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3()) * Matrix4::Scale(Vector3(0.1f)));
		else
			fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(light.posDir.x, light.posDir.y, light.posDir.z)) * Matrix4::Scale(Vector3(0.1f)));

		lightModel.Render();

		lightShader.Unbind();

		//terrain.Render();

		BF::Engine::GetContext().SwapBuffers();
	}
}