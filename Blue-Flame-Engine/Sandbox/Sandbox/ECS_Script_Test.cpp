#include "ECS_Script_Test.h"
#include "ScriptTest.h"

namespace ECS_Script_Test
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
	using namespace BF::Scripting;

	ECS_Script_Test::ECS_Script_Test()
	{
	}

	ECS_Script_Test::~ECS_Script_Test()
	{
	}

	void ECS_Script_Test::Initialize()
	{
		scene = new Scene(camera);

		App::Initialize();

		BF::Input::Mouse::ShowMouseCursor(true);

		BF::Engine::GetContext().EnableVsync(false);
		BF::Engine::GetContext().SetWindingOrder(WindingOrder::Clockwise);
		BF::Engine::GetContext().CullFace(CullingType::Back);
		//BF::Engine::LimitFrameRate(60.0f);

		camera.Initialize(Matrix4::Orthographic(-((int)Engine::GetWindow().GetClientWidth() / 2), (int)(Engine::GetWindow().GetClientWidth() / 2), ((int)Engine::GetWindow().GetClientHeight() / 2), -(int)(Engine::GetWindow().GetClientHeight() / 2), -1.0f, 1.0f));

		/*GameObject* parent = scene->AddGameObject(new GameObject(*scene, "parent"));
		parent->GetTransform()->SetPosition(Vector3f(100, 100, 100));
		parent->GetTransform()->SetScale(Vector3f(0.5, 0.5, 0.5));*/

		GameObject* RegularPolygonGameObject = scene->AddGameObject(new GameObject(*scene, "RegularPolygon A"));
		RegularPolygonGameObject->GetTransform()->SetPosition(Vector3f(0, 0, 0));
		RegularPolygonGameObject->GetTransform()->SetScale(Vector3f(1, 1, 1));
		RegularPolygon* rp = (RegularPolygon*)RegularPolygonGameObject->AddComponent(new RegularPolygon(Vector2i(100, 200), Vector2f(0, 0), 2, Color::Blues::DarkBlue()));
		Script* script = (Script*)RegularPolygonGameObject->AddComponent(new ScriptTest());

		Texture2D* t = new Texture2D();
		t->Load("C:/engine/Blue-Flame-Engine/Sandbox/Assets/Textures/tilea5.png");

		GameObject* sprite = scene->AddGameObject(new GameObject(*scene, "sprite"));
		sprite->AddComponent(new Sprite(t, Vector2f(0, 0)));
		sprite->GetTransform()->SetPosition(Vector3f(0, 0, 0));
		sprite->GetTransform()->SetScale(Vector3f(1, 1, 1));
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
		camera.Update();
		App::Update();
	}

	void ECS_Script_Test::Render()
	{
		BF::Engine::GetContext().Clear(BufferClearType::ColorAndDepth, Color(0.5, 0.0f, 0.0f, 1.0f));
		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}