#include "TestApp.h"
#include "BF/IO/SceneLoader.h"

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
		//BF::IO::SceneLoader::Load("Assets/Scenes/TestScene.scene");

		//BF::Engine::LimitFrameRate(1.0f);
		//BF::Engine::GetContext().EnableVsync(false);

		scene = new BF::Application::Scene();
		scene->Initialize();
		scene->Load();

		RegularPolygon* regularPolygon = (RegularPolygon*)scene->instantiate("regularPolygon", new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon2 = (RegularPolygon*)scene->instantiate("regularPolygon2", new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon3 = (RegularPolygon*)scene->instantiate("regularPolygon3", new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Reds::DarkRed()), regularPolygon);
		//Button* b = (Button*)scene->instantiate("button", new Button());
		
		BF::Graphics::GUI::MenuStrip::MenuStrip* m = (BF::Graphics::GUI::MenuStrip::MenuStrip*)scene->instantiate("MenuStrip", new BF::Graphics::GUI::MenuStrip::MenuStrip());

		m->Instantiate("File");
		m->Instantiate("File");
		m->Instantiate("File");
		m->Instantiate("File");

		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	}

	void TestApp::Load()
	{
		
	}

	void TestApp::Update()
	{
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		scene->Update();
		camera.Update();
	}

	void TestApp::Render()
	{
		BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		scene->Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}