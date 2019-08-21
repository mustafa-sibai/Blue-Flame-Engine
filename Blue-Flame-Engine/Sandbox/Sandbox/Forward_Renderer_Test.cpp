#include "Forward_Renderer_Test.h"
#include "BF/IO/ResourceManager.h"

namespace Forward_Renderer_Test
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::IO;

	Forward_Renderer_Test::Forward_Renderer_Test()/* :
		directionalLight(false)*/
	{
	}

	Forward_Renderer_Test::~Forward_Renderer_Test()
	{
	}

	void Forward_Renderer_Test::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableDepthBuffer(true);
		BF::Engine::GetContext().EnableVsync(false);
		//BF::Engine::LimitFrameRate(60.0f);
		BF::Engine::GetContext().SetPrimitiveType(PrimitiveType::Triangles);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);

		App::Initialize();

		GameObject* cameraGameObject = scene->AddGameObject(new GameObject("Camera"));
		Camera* camera = (Camera*)cameraGameObject->AddComponent(new Camera(Matrix4::Perspective(45.0f, BF::Engine::GetWindow().GetAspectRatio(), 0.1f, 1500.0f)));
		camera->gameObject->GetTransform()->SetPosition(Vector3f(0, 3, -10));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.5, 0.0f, 0.0f, 1.0f));

		GameObject* planeGameObject = scene->AddGameObject(new GameObject("Plane"));

		/*MeshData* meshData = ResourceManager::Load<MeshData>("../Sandbox/Assets/Models/Plane/PPlane.bfx");
		Mesh* planeMesh = (Mesh*)planeGameObject->AddComponent(new Mesh(meshData));
		planeMesh->gameObject->GetTransform()->SetPosition(Vector3f(0, -1, 5));
		planeMesh->gameObject->GetTransform()->SetScale(Vector3f(3, 3, 3));*/

		//constantBuffer.Create(sizeof(LightBuffer), 1);

		/*
		TextureData* myTexture = BF::IO::ResourceManager::Load<TextureData>("texture2DName.png");
		Texture2D* texture = new Texture2D();
		texture->Create(myTexture, BF::Graphics::API::Texture::Format::R8G8B8A8);*/
		
	}

	void Forward_Renderer_Test::Load()
	{
		App::Load();

		//lights.posDir.w = 1.0f;
		PN1.LoadStandardShader(ShaderType::P);
		//PN2.LoadStandardShader(ShaderType::PN);
		//PN3.LoadStandardShader(ShaderType::PN);

		int i = 0;

		/*BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);
		crateMaterial1 = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial1->Initialize();
		crateMaterial1->shader = &PN1;

		//crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial1->colorBuffer.ambientColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial1->colorBuffer.diffuseColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial1->colorBuffer.specularColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial1->colorBuffer.shininess = 256;

		transform = (Transform*)scene->GetGameObjects()[i]->GetComponents()[0];
		transform->position = Vector3f(0.0f, 2.0f, 0.0f);
		transform->rotation = Vector3f(0, 0, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[i]->GetComponents()[1])->SetBuffers(crateMaterial1);


		//-----------------------------------------------------------------------------------

		i++;

		BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);
		crateMaterial2 = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial2->Initialize();
		crateMaterial2->shader = &PN2;

		//crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial2->colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial2->colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial2->colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial2->colorBuffer.shininess = 256;

		transform = (Transform*)scene->GetGameObjects()[i]->GetComponents()[0];
		transform->position = Vector3f(3.0f, 2.0f, 0.0f);
		transform->rotation = Vector3f(0, 0, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[i]->GetComponents()[1])->SetBuffers(crateMaterial2);

		//-----------------------------------------------------------------------------------

		i++;

		BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);
		crateMaterial3 = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial3->Initialize();
		crateMaterial3->shader = &PN3;

		//crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial3->colorBuffer.ambientColor = Color(0.0f, 1.0f, 0.0f, 1.0f);
		crateMaterial3->colorBuffer.diffuseColor = Color(0.0f, 1.0f, 0.0f, 1.0f);
		crateMaterial3->colorBuffer.specularColor = Color(0.0f, 1.0f, 0.0f, 1.0f);
		crateMaterial3->colorBuffer.shininess = 256;

		transform = (Transform*)scene->GetGameObjects()[i]->GetComponents()[0];
		transform->position = Vector3f(6.0f, 2.0f, 0.0f);
		transform->rotation = Vector3f(0, 0, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[i]->GetComponents()[1])->SetBuffers(crateMaterial3);

		//-----------------------------------------------------------------------------------

		i++;

		BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);
		crateMaterial4 = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial4->Initialize();
		crateMaterial4->shader = &PN2;

		//crateMaterial->diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//crateMaterial->specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		crateMaterial4->colorBuffer.ambientColor = Color(1.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial4->colorBuffer.diffuseColor = Color(1.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial4->colorBuffer.specularColor = Color(1.0f, 0.0f, 1.0f, 1.0f);
		crateMaterial4->colorBuffer.shininess = 256;

		transform = (Transform*)scene->GetGameObjects()[i]->GetComponents()[0];
		transform->position = Vector3f(9.0f, 2.0f, 0.0f);
		transform->rotation = Vector3f(0, 0, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[i]->GetComponents()[1])->SetBuffers(crateMaterial4);

		//-----------------------------------------------------------------------------------

		i++;

		BF::IO::BFXLoader::Load("Assets/Models/TexturedCube/TexturedCube.bfx", *scene);
		crateMaterial5 = new BF::Graphics::Materials::MeshMaterial();

		crateMaterial5->Initialize();
		crateMaterial5->shader = &PN1;

		//diffuseMap.Load("Assets/Models/Crate/Crate/Crate_color.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//specularMap.Load("Assets/Models/Crate/Crate/Crate_specular.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);
		//normalMap.Load("Assets/Models/Crate/Crate/Crate_normal.png", Texture::Wrap::ClampToEdge, Texture::Filter::AnisotropicX16);

		//crateMaterial5->SetDiffuseMap(diffuseMap);
		//crateMaterial5->SetSpecularMap(specularMap);
		//crateMaterial5->SetNormalMap(normalMap);

		crateMaterial5->colorBuffer.ambientColor = Color(0.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial5->colorBuffer.diffuseColor = Color(0.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial5->colorBuffer.specularColor = Color(0.0f, 1.0f, 1.0f, 1.0f);
		crateMaterial5->colorBuffer.shininess = 256;

		transform = (Transform*)scene->GetGameObjects()[i]->GetComponents()[0];
		transform->position = Vector3f(12.0f, 2.0f, 0.0f);
		transform->rotation = Vector3f(0, 0, 0);
		transform->scale = Vector3f(1.0f);

		((Mesh*)scene->GetGameObjects()[i]->GetComponents()[1])->SetBuffers(crateMaterial5);

		//-----------------------------------------------------------------------------------

		i++;*/

		//BF::IO::BFXLoader::Load("Assets/Models/Plane.bfx", *scene);

		/*planeMaterial = new BF::Graphics::Materials::MeshMaterial();

		planeMaterial->Initialize();
		planeMaterial->shader = &PN1;

		planeMaterial->colorBuffer.ambientColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		planeMaterial->colorBuffer.diffuseColor = Color(1.0f, 0.0f, 0.0f, 1.0f);
		planeMaterial->colorBuffer.specularColor = Color(1.0f, 0.0f, 0.0f, 1.0f);*/
		//planeMaterial->colorBuffer.shininess = 256;
		//Mesh* m = new Mesh(BF::Graphics::Mesh::PresetMeshes::Plane);


		
		/*for (size_t j = 0; j < 1; j++)
		{
			for (size_t k = 0; k < 25; k++)
			{
				//BF::IO::BFXLoader::Load("Assets/Models/Test/Plane.bfx", *scene);

				//GameObject* gameObject = scene->AddGameObject(new GameObject("Mesh " + std::to_string(i)));
				//scene->AddComponentToGameObject(gameObject, new Mesh(BF::Graphics::Mesh::PresetMeshes::Plane));

				

				Transform* planeTransform = (Transform*)scene->GetGameObjects()[k + j * 25]->GetComponents()[0];
				planeTransform->SetPosition(Vector3f(25 * k, 25 * j, 0.0f));
				planeTransform->SetRotation(0, Vector3f(0, 0, 0));
				planeTransform->SetScale(Vector3f(10.0f));
				//planeTransform->angle = 90 + k * 10;

				//BF::Graphics::Materials::MeshMaterial* planeMaterialz = new BF::Graphics::Materials::MeshMaterial();
				planeMaterial = new BF::Graphics::Materials::MeshMaterial();
				planeMaterial->Initialize();
				planeMaterial->shader = &PN1;

				if (k <= 0)
				{
					planeMaterial->colorBuffer.ambientColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
					planeMaterial->colorBuffer.diffuseColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
					planeMaterial->colorBuffer.specularColor = Color(0.0f, 0.0f, 1.0f, 1.0f);
				}
				else
				{
					planeMaterial->colorBuffer.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
					planeMaterial->colorBuffer.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
					planeMaterial->colorBuffer.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
				}

				((Mesh*)scene->GetGameObjects()[k + j * 25]->GetComponents()[1])->SetBuffers(planeMaterial);
			}
		}*/
		


		//lightPosition = Vector3f(50.0f, 10.0f, -1.0f);
		//fpsCamera.SetViewMatrix(Math::Matrix4::LookAt(Vector3f(8.0f, 10.0f, -1.0f), Vector3f(0, 0, 0), Vector3f::Up()));
	}

	void Forward_Renderer_Test::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void Forward_Renderer_Test::Update(double deltaTime)
	{
		App::Update(deltaTime);
		//transform->angle += 0.1f * BF::Engine::GetDeltaTime();
		//transform->position -= Vector3f(0.0f, 0.0f, 0.1f);
		//fpsCamera.Update();
	}

	void Forward_Renderer_Test::Render()
	{
		/*lights.posDir = Vector4f(lightPosition.x, lightPosition.y, lightPosition.z, 0.0f);
		lights.ambientColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		lights.diffuseColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
		lights.specularColor = Color(1.0f, 1.0f, 1.0f, 1.0f);
 	
		lights.constant = 1.0f;
		lights.linear = 0.007f;
		lights.quadratic = 0.0002f;

		constantBuffer.Update(&lights, sizeof(LightBuffer));*/

		App::Render();
	}
}