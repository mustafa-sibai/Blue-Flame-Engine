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
		cubeModel(shader), crateModel(shader), planeModel(shader),
		lightModel{ Model(lightShader), Model(lightShader), Model(lightShader), Model(lightShader) },
		directionalLight(false)
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

		constantBuffer.Create(sizeof(Lights), 1);
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

		crateModel.Load("Assets/Models/Crate/Crate.bfx");
		planeModel.Load("Assets/Models/Plane.bfx");
		cubeModel.Load("Assets/Models/Cube.bfx");

		//------------------------------------------ Light Models ----------------------------------------------
		for (size_t i = 0; i < 4; i++)
		{
			lightModel[i].Load("Assets/Models/Cube.bfx");
			light.lights[i].posDir.w = 1.0f;
		}
		//------------------------------------------ Light Models ----------------------------------------------

		//, Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16
		floorMaterial.diffuseMap.Load("Assets/Textures/diffuseMap.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		floorMaterial.specularMap.Load("Assets/Textures/specularMap.png");
		floorMaterial.normalMap.Load("Assets/Textures/normalMap.jpg");

		crateMaterial.diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial.normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial.specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
	}

	/*void _3DScene::FixedUpdate()
	{

	}*/

	void _3DScene::Update()
	{
		angle += 0.1f * BF::Engine::GetDeltaTime();
		fpsCamera.Update();

		//BF_LOG_INFO("%f, %f, %f", fpsCamera.GetPosition().x, fpsCamera.GetPosition().y, fpsCamera.GetPosition().z);

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num1))
			lightIndex = 0;

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num2))
			lightIndex = 1;

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num3))
			lightIndex = 2;

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::Num4))
			lightIndex = 3;


		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::U))
			directionalLight = true;

		if (Keyboard::IsKeyPressed(Keyboard::Key::Code::O))
			directionalLight = false;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::L))
			lights.lights[lightIndex].posDir.x += 0.5f;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::J))
			lights.lights[lightIndex].posDir.x -= 0.5f;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::P))
			lights.lights[lightIndex].posDir.y += 0.5f;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::Semicolon))
			lights.lights[lightIndex].posDir.y -= 0.5f;


		if (Keyboard::IsKeyDown(Keyboard::Key::Code::I))
			lights.lights[lightIndex].posDir.z += 0.5f;

		if (Keyboard::IsKeyDown(Keyboard::Key::Code::K))
			lights.lights[lightIndex].posDir.z -= 0.5f;
	}

	void _3DScene::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		skybox.Render();

		skybox.Bind();
		shader.Bind();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, -2.5f, 0.0f)) * Matrix4::Rotate(0.0f, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(10.0f)));
		planeModel.Render();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, 0.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f)));

		crateMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial.colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		crateMaterial.colorBuffer.shininess = 8.0f;
		materialConstantBuffer.Update(&crateMaterial, sizeof(crateMaterial.colorBuffer));
		crateMaterial.Bind();

		crateModel.Render();

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(0.0f, -1.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3(0, 1, 0)) * Matrix4::Scale(Vector3(1.0f, 1.0f, 1.0f)));

		//material.colorBuffer.ambientColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.diffuseColor = Color(1.0f, 0.5f, 0.31f, 1.0f);
		//material.colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);

		floorMaterial.colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		floorMaterial.colorBuffer.shininess = 128.0f;
		materialConstantBuffer.Update(&floorMaterial, sizeof(floorMaterial.colorBuffer));
		floorMaterial.Bind();

		cubeModel.Render();

		shader.Unbind();
		skybox.Unbind();


		//----------------------------------------------- Light 1 -------------------------------------------
		lightShader.Bind();

		for (size_t i = 0; i < 4; i++)
		{
			lights.lights[i].ambientColor = Color(0.0f, 0.0f, 0.0f, 1.0f);
			lights.lights[i].diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
			lights.lights[i].specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		}

		constantBuffer.Update(&lights, sizeof(Lights));

		for (size_t i = 0; i < 4; i++)
		{
			if (directionalLight)
				fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3()) * Matrix4::Scale(Vector3(0.1f)));
			else
				fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3(lights.lights[i].posDir.x, lights.lights[i].posDir.y, lights.lights[i].posDir.z)) * Matrix4::Scale(Vector3(0.1f)));
		
			lightModel[i].Render();
		}

		

		lightShader.Unbind();
		//----------------------------------------------- Light 1 -------------------------------------------


		//terrain.Render();

		BF::Engine::GetContext().SwapBuffers();
	}
}