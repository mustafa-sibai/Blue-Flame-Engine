#pragma once
#include <BF/BlueFlame.h>
#include <BF/Platform/API/Vulkan/VKContext.h>

#include "_2DScene.h"
#include "_3DScene.h"

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	//BF::Platform::API::Vulkan::VKContext vKContext;

	Engine engine(BF::Application::Window("Blue Flame Engine", 0, 0, 1920, 1080, BF::Application::WindowStyle::Windowed), BF::Graphics::API::RenderAPI::OpenGL);

	BF::Application::SceneManager::AddNewScene(new _2DScene::_2DScene());
	BF::Application::SceneManager::AddNewScene(new _3DScene::_3DScene());

	//BF::Application::SceneManager::GetScene(0).Run();
	BF::Application::SceneManager::GetScene(1).Run();

	engine.Run();

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