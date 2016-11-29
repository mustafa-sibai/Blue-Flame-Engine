#pragma once
#include <BF/BlueFlame.h>

#include "_3DScene.h"
#include "_2DScene.h"

#include <windows.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	BF::Application::Window window("Blue Flame Engine", 0, 0, 1920, 1080, BF::Application::WindowStyle::ResizableWindow);
	//_3DScene::_3DScene _3dScene(&window);
	_2DScene::_2DScene _2dScene(&window);

	while (window.IsOpen())
	{
		window.Update();
		//_3dScene.Draw();
		_2dScene.Draw();
	}

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