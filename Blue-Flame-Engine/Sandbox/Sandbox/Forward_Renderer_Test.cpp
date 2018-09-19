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
		scene = new Scene(fpsCamera);
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
		BF::IO::BFXLoader::Load("Assets/Models/Plane.bfx", *scene);

		lights.posDir.w = 1.0f;

		PUVNTB.LoadStandardShader(ShaderType::PUVN);
		PN.LoadStandardShader(ShaderType::PN);

		crateMaterial = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial->Initialize();
		crateMaterial->shader = &PUVNTB;

		crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial->colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial->colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial->colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		crateMaterial->colorBuffer.shininess = 8.0f;

		transform = (Transform*)scene->GetGameObjects()[0]->GetComponents()[0];
		transform->position = Vector3f(0.0f, 0.0f, 5.0f);
		transform->rotation = Vector3f(0, 1, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[0]->GetComponents()[1])->material = crateMaterial;
		((Mesh*)scene->GetGameObjects()[0]->GetComponents()[1])->SetBuffers();


		planeMaterial = new BF::Graphics::Materials::MeshMaterial();

		planeMaterial->Initialize();
		planeMaterial->shader = &PN;

		planeMaterial->colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		planeMaterial->colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		planeMaterial->colorBuffer.specularColor = Color(0.5f, 0.5f, 0.5f, 1.0f);
		planeMaterial->colorBuffer.shininess = 8.0f;

		Transform* planeTransform = (Transform*)scene->GetGameObjects()[1]->GetComponents()[0];
		planeTransform->position = Vector3f(0.0f, -2.0f, 5.0f);
		planeTransform->rotation = Vector3f(0, 0, 0);
		planeTransform->scale = Vector3f(10.0f);

		((Mesh*)scene->GetGameObjects()[1]->GetComponents()[1])->material = planeMaterial;
		((Mesh*)scene->GetGameObjects()[1]->GetComponents()[1])->SetBuffers();
	}

	void Forward_Renderer_Test::Update()
	{
		App::Update();

		transform->angle += 0.1f * BF::Engine::GetDeltaTime();
		fpsCamera.Update();
	}

	void Forward_Renderer_Test::Render()
	{
		BF::Engine::GetContext().Clear(Color(0.5, 0.0f, 0.0f, 1.0f));

		lights.posDir = Vector4f(2.0f, 1.0f, 0.0f, 1.0f);
		lights.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		lights.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		lights.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);

		lights.constant = 1.0f;
		lights.linear = 0.22f;
		lights.quadratic = 0.20f;

		constantBuffer.Update(&lights, sizeof(LightBuffer));

		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}