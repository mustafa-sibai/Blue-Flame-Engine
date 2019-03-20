#include "ECS_Script_Test.h"
#include "ScriptTest.h"
#include "BF/IO/ResourceManager.h"

namespace ECS_Script_Test
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::Materials;
	using namespace BF::Graphics::Renderers::SpriteRendererComponents;
	using namespace BF::ECS;
	using namespace BF::Math;
	using namespace BF::System;
	using namespace BF::Scripting;

	ECS_Script_Test::ECS_Script_Test()
	{
	}

	ECS_Script_Test::~ECS_Script_Test()
	{
	}

	void ECS_Script_Test::Initialize()
	{
		scene = new Scene(*this);

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		/*GameObject* parent = scene->AddGameObject(new GameObject(*scene, "parent"));
		parent->GetTransform()->SetPosition(Vector3f(100, 100, 100));
		parent->GetTransform()->SetScale(Vector3f(0.5, 0.5, 0.5));*/

		GameObject* CameraGameObject = scene->AddGameObject(new GameObject("Camera"));
		Camera* camera = (Camera*)CameraGameObject->AddComponent(new Camera(Matrix4::Orthographic(-(Engine::GetWindow().GetClientSize().x / 2), Engine::GetWindow().GetClientSize().x / 2, Engine::GetWindow().GetClientSize().y / 2, -(Engine::GetWindow().GetClientSize().y / 2), -1.0f, 1.0f)));

		camera->SetClearType(BufferClearType::ColorAndDepth);
		camera->SetClearColor(Color(0.5, 0.0f, 0.0f, 1.0f));

		/*GameObject* RegularPolygonGameObject = scene->AddGameObject(new GameObject("RegularPolygon A"));
		RegularPolygonGameObject->GetTransform()->SetPosition(Vector3f(0, 0, 0));
		RegularPolygonGameObject->GetTransform()->SetScale(Vector3f(1, 1, 1));
		RegularPolygon* rp = (RegularPolygon*)RegularPolygonGameObject->AddComponent(new RegularPolygon(Vector2i(100, 200), Vector2f(0, 0), 2, RenderLayer("Default"), Color::Blues::DarkBlue()));
		ScriptTest* script = (ScriptTest*)RegularPolygonGameObject->AddComponent(new ScriptTest());

		ScriptTest* script2 = RegularPolygonGameObject->GetComponent<ScriptTest>();

		Texture2D* texture = new Texture2D();
		texture->Create(BF::IO::ResourceManager::Load<TextureData>("../Sandbox/Assets/Textures/tilea5.png"), BF::Graphics::API::Texture::Format::R8G8B8A8);

		GameObject* sprite = scene->AddGameObject(new GameObject("sprite"));
		sprite->AddComponent(new Sprite(texture, Vector2f(0, 0)));
		sprite->GetTransform()->SetPosition(Vector3f(0, 0, 0));
		sprite->GetTransform()->SetScale(Vector3f(1, 1, 1));*/

		App::Initialize();
	}

	void ECS_Script_Test::Load()
	{
		App::Load();
	}

	void ECS_Script_Test::PostLoad()
	{
		App::PostLoad();
		App::RunScene(*scene);
	}

	void ECS_Script_Test::Update()
	{
		App::Update();
	}

	void ECS_Script_Test::Render()
	{
		App::Render();
	}
}