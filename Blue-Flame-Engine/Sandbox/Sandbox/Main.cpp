#pragma once
#include <BF/BlueFlame.h>
#include <BF/Engine.h>

#include "_2DScene.h"
#include "_3DScene.h"

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	BF::Application::Window window("Blue Flame Engine", 0, 0, 1920, 1080, BF::Application::WindowStyle::Windowed);
	Engine* engine = new Engine(window, BF::Graphics::API::Context(&window, BF::Graphics::API::RenderAPI::OpenGL));

	SceneManager::AddNewScene(new _2DScene::_2DScene());
	SceneManager::AddNewScene(new _3DScene::_3DScene());

	SceneManager::GetScene(0).Run();
	//SceneManager::GetScene(1).Run();

	engine->Run();

	/*
		TCHAR  buffer[MAX_PATH];
		GetModuleFileName(NULL, buffer, MAX_PATH);

		for (size_t i = 0; i < MAX_PATH; i++)
		{
			cout << (char)buffer[i];
		}
		*/
		/*
			BF::Audio::SoundManager soundManager;
			BF::Audio::Sound sound;

			sound.Load("Assets/Audio/16test.wav");
			sound.Play(true);
			
	
	system("PAUSE");
	*/
	return 0;
}