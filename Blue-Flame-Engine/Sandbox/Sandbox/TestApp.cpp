#include "TestApp.h"

namespace TestApp
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	TestApp::TestApp()
	{
	}

	TestApp::~TestApp()
	{
	}

	void TestApp::Initialize()
	{
		scene = new BF::Application::Scene();
		BF::Application::SceneManager::AddNewScene(scene);

		RegularPolygon* regularPolygon = (RegularPolygon*)scene->instantiate("regularPolygon", new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon2 = (RegularPolygon*)scene->instantiate("regularPolygon2", new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon3 = (RegularPolygon*)scene->instantiate("regularPolygon3", new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Blues::DarkBlue()), regularPolygon);
		Button* b = (Button*)scene->instantiate("button", new Button());

		App::Initialize();
		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	}

	void TestApp::Load()
	{
		App::Load();
	}

	void TestApp::Update()
	{
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		App::Update();
		camera.Update();
	}

	void TestApp::Render()
	{
		BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}