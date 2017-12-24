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

	TestApp::TestApp() :
		exitItem(nullptr)
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

		scene = new Scene();
		scene->Initialize();
		scene->Load();

		RegularPolygon* regularPolygon = (RegularPolygon*)scene->Instantiate("regularPolygon", new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon2 = (RegularPolygon*)scene->Instantiate("regularPolygon2", new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 0, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon3 = (RegularPolygon*)scene->Instantiate("regularPolygon3", new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Reds::DarkRed()), regularPolygon);
		//Button* b = (Button*)scene->instantiate("button", new Button());
		
		MenuStrip::MenuStrip* m = (MenuStrip::MenuStrip*)scene->Instantiate("MenuStrip", new MenuStrip::MenuStrip());
		MenuStrip::MenuItem* fileMenu = m->Instantiate("File");
		MenuStrip::MenuItem* newMenu = fileMenu->Instantiate("New");
		MenuStrip::MenuItem* Xo = newMenu->Instantiate("Xo");
		Xo->Instantiate("LOL");
		newMenu->Instantiate("oX");

		fileMenu->Instantiate("Open");
		fileMenu->Instantiate("Save");
		fileMenu->Instantiate("Save As");
		exitItem = fileMenu->Instantiate("Exit");

		MenuStrip::MenuItem* editMenu = m->Instantiate("Edit");
		editMenu->Instantiate("Copy");

		MenuStrip::MenuItem* viewMenu = m->Instantiate("View");
		viewMenu->Instantiate("Scene");

		MenuStrip::MenuItem* helpMenu = m->Instantiate("Help");
		helpMenu->Instantiate("About");

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

		if (exitItem->IsPressed())
			Engine::Exit();
	}

	void TestApp::Render()
	{
		BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		scene->Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}