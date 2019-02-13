#include "TestApp.h"
#include "BF/IO/SceneLoader.h"
#include "BF/Graphics/GUI2/Canves.h"
#include "BF/Graphics/GUI2/Button.h"
//#include "BF/Graphics/GUI/TabWindow/TabWindow.h"

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

	TestApp::TestApp()/* :
		exitItem(nullptr)*/
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
		SetMainScene(*scene);

		//GetSceneManager().AddScene();
		//scene = GetSceneManager().LoadScene(0);

		
		/*RegularPolygon* regularPolygon =  (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon", new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 5, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon2 = (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon2", new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 2, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon3 = (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon3", new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Yellows::Yellow()));*/
		

		GameObject* regularPolygon = scene->GetRootGameNode().InstantiateChildGameObject("regularPolygon");
		GameObject* regularPolygon2 = scene->GetRootGameNode().InstantiateChildGameObject("regularPolygon2");
		GameObject* regularPolygon3 = scene->GetRootGameNode().InstantiateChildGameObject("regularPolygon3");

		regularPolygon->AddComponent(new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 5, Color::Blues::DarkBlue()));
		regularPolygon2->AddComponent(new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 2, Color::Blues::DarkBlue()));
		regularPolygon3->AddComponent(new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Yellows::Yellow()));


		GameObject* canves = scene->GetRootGameNode().InstantiateChildGameObject("canves");
		canves->AddComponent(new Canves());

		GameObject* button = canves->InstantiateChildGameObject("Button");
		button->AddComponent(new Button());

		/*
		scene->Destroy(regularPolygon);

		RegularPolygon* regularPolygon4 = (RegularPolygon*)scene->Instantiate("regularPolygon4", new RegularPolygon(Math::Rectangle(0, 420, 100, 100), 0, Color::Greys::DarkGray())/*, regularPolygon*//*);
		
		//Button* b = (Button*)scene->instantiate("button", new Button());
		
		/*
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

		BF::Graphics::GUI::TabWindow::TabWindow* tabWindow = (BF::Graphics::GUI::TabWindow::TabWindow*)scene->Instantiate("tabWindow", new BF::Graphics::GUI::TabWindow::TabWindow());
		tabWindow->SetPosition(Vector2f(100, 100));
		//delete tabWindow;

		scene->Destroy(tabWindow);
		*/


		camera.Initialize(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
	}

	void TestApp::Load()
	{
		App::Load();
	}

	void TestApp::Update()
	{
		App::Update();
		camera.SetProjectionMatrix(Matrix4::Orthographic(0.0f, Engine::GetWindow().GetClientWidth(), 0.0f, Engine::GetWindow().GetClientHeight(), -1.0f, 1.0f));
		camera.Update();
		/*
		if (exitItem->IsPressed())
			Engine::Exit();*/
	}

	void TestApp::Render()
	{
		BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}