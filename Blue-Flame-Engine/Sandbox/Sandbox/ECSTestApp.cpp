#include "ECSTestApp.h"
#include "BF/IO/SceneLoader.h"
//#include "BF/Graphics/GUI/TabWindow/TabWindow.h"

namespace ECSTestApp
{
	using namespace BF;
	using namespace BF::AI;
	using namespace BF::Application;
	using namespace BF::Graphics;
	using namespace BF::Graphics::API;
	using namespace BF::Graphics::Renderers;
	using namespace BF::ECS;
	//using namespace BF::Graphics::GUI;
	using namespace BF::Math;
	using namespace BF::System;

	ECSTestApp::ECSTestApp()/* :
		exitItem(nullptr)*/
	{
	}

	ECSTestApp::~ECSTestApp()
	{
	}

	void ECSTestApp::Initialize()
	{
		//BF::IO::SceneLoader::Load("Assets/Scenes/TestScene.scene");

		//BF::Engine::LimitFrameRate(1.0f);
		//BF::Engine::GetContext().EnableVsync(false);

		scene = new Scene(camera);
		SetMainScene(*scene);

		//GetSceneManager().AddScene();
		//scene = GetSceneManager().LoadScene(0);

		
		/*RegularPolygon* regularPolygon =  (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon", new RegularPolygon(Math::Rectangle(100, 120, 100, 100), 5, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon2 = (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon2", new RegularPolygon(Math::Rectangle(120, 0, 100, 100), 2, Color::Blues::DarkBlue()));
		RegularPolygon* regularPolygon3 = (RegularPolygon*)scene->GetRootGameNode().Instantiate("regularPolygon3", new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 0, Color::Yellows::Yellow()));*/
		

		

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

		spriteGameObject = scene->AddGameObject(new GameObject("First Game Object"));
		//scene->AddGameObject(spriteGameObject);

		regularPolygon = (RegularPolygon*)scene->AddComponentToGameObject(spriteGameObject, new RegularPolygon(Math::Rectangle(0, 0, 100, 100), 1, Color(1)));
		//regularPolygon2 = (RegularPolygon*)scene->AddComponentToGameObject(spriteGameObject, new RegularPolygon(Math::Rectangle(50, 0, 100, 100), 0, Color(0, 1, 0, 1)));


		//(RegularPolygon*)scene->AddComponentToGameObject(spriteGameObject, regularPolygon);

		camera.Initialize(Matrix4::Orthographic(-((int)Engine::GetWindow().GetClientWidth() / 2), (int)(Engine::GetWindow().GetClientWidth() / 2), -((int)Engine::GetWindow().GetClientHeight() / 2), (int)(Engine::GetWindow().GetClientHeight() / 2), -1.0f, 1.0f));
		//BF::Engine::GetContext().EnableVsync(false);
	}

	void ECSTestApp::Load()
	{
		App::Load();
	}

	float x = 0.0f;
	float y = 0.0f;

	void ECSTestApp::Update()
	{
		App::Update();

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::Code::A))
		{
			scene->RemoveGameObject(spriteGameObject);
			std::cout << "WTDF" << std::endl;
		}

		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::Code::B))
		{
			regularPolygon->zLayer = 0;
			regularPolygon2->zLayer = 1;
			
		}
		if (BF::Input::Keyboard::IsKeyPressed(BF::Input::Keyboard::Key::Code::C))
		{
			regularPolygon->zLayer = 1;
			regularPolygon2->zLayer = 0;
		}

		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::RightArrow))
		{
			x++;
		}
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::LeftArrow))
		{
			x--;
		}
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::UpArrow))
		{
			y++;
		}
		if (BF::Input::Keyboard::IsKeyHeldDown(BF::Input::Keyboard::Key::Code::DownArrow))
		{
			y--;
		}
		camera.SetViewMatrix(Math::Matrix4::Translate(Vector3f(x, y, 0.0f)));

		/*
		if (exitItem->IsPressed())
			Engine::Exit();*/
	}

	void ECSTestApp::Render()
	{
		//BF::Engine::GetContext().Clear(Color::Reds::DarkRed());
		App::Render();
		BF::Engine::GetContext().SwapBuffers();
	}
}