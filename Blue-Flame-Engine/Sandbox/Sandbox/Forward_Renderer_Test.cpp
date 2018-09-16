#include "Forward_Renderer_Test.h"

namespace Forward_Renderer_Test
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;

	Forward_Renderer_Test::Forward_Renderer_Test() :
		directionalLight(false)
	{
	}

	Forward_Renderer_Test::~Forward_Renderer_Test()
	{
	}

	void Forward_Renderer_Test::Initialize()
	{
		scene = new Scene();
		SetMainScene(*scene);

		App::Initialize();

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableDepthBuffer(true);
		BF::Engine::GetContext().EnableVsync(true);
		BF::Engine::LimitFrameRate(60.0f);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::TriangleList);

		fpsCamera.Initialize(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f));

		constantBuffer.Create(sizeof(LightBuffer), 1);
	}

	void Forward_Renderer_Test::Load()
	{
		App::Load();

		BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);

		lights.posDir.w = 1.0f;

		crateMaterial = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial->Initialize();
		crateMaterial->shader.LoadStandardShader(ShaderType::PUVN);

		crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial->colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial->colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial->colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		crateMaterial->colorBuffer.shininess = 8.0f;

		((Mesh*)scene->GetGameObjects()[0]->GetComponents()[0])->material = crateMaterial;
		((Mesh*)scene->GetGameObjects()[0]->GetComponents()[0])->SetBuffers();
	}

	void Forward_Renderer_Test::Update()
	{
		App::Update();

		angle += 0.1f * BF::Engine::GetDeltaTime();
		fpsCamera.Update();
	}

	void Forward_Renderer_Test::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		lights.posDir = Vector4f(2.5f, 0.0f, 0.0f, 1.0f);
		lights.ambientColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		lights.diffuseColor = Color(0.0f, 1.0f, 0.0f, 1.0f);
		lights.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);

		lights.constant = 1.0f;
		lights.linear = 0.045f;
		lights.quadratic = 0.0075f;

		constantBuffer.Update(&lights, sizeof(LightBuffer));

		fpsCamera.SetModelMatrix(Matrix4::Translate(Vector3f(0.0f, 0.0f, 5.0f)) * Matrix4::Rotate(angle, Vector3f(0, 1, 0)) * Matrix4::Scale(Vector3f(1.0f)));

		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}