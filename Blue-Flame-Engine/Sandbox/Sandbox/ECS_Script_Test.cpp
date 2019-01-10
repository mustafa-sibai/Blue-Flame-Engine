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
		//BF::Engine::LimitFrameRate(60.0f);

		camera.Initialize(Matrix4::Orthographic(-((int)Engine::GetWindow().GetClientWidth() / 2), (int)(Engine::GetWindow().GetClientWidth() / 2), -((int)Engine::GetWindow().GetClientHeight() / 2), (int)(Engine::GetWindow().GetClientHeight() / 2), -1.0f, 1.0f));
		
		GameObject* RegularPolygonGameObject = scene->AddGameObject(new GameObject("RegularPolygon A"));
		RegularPolygonGameObject->GetTransform()->position = Vector3f(-50, -50, 0);
		RegularPolygonGameObject->GetTransform()->scale = Vector3f(0.5f, 0.5f, 0);
		RegularPolygon* rp = (RegularPolygon*)scene->AddComponentToGameObject(RegularPolygonGameObject, new RegularPolygon(Vector2i(100, 100), 2, Color::Blues::DarkBlue()));
	
		GameObject* scriptTest = scene->AddGameObject(new GameObject("Script Test"));
		Script* script = (Script*)scene->AddComponentToGameObject(scriptTest, new ScriptTest());
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