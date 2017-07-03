#include <BF/BlueFlame.h>
//#include <BF/Engine.h>
//#include <BF/Application/Window.h>
//#include <BF/Application/SceneManager.h>
//#include <BF/Platform/API/Vulkan/VKContext.h>

#include "_2DScene.h"
//#include "_3DScene.h"
#include "new3DScene.h"
#include "_3DScene_AF_Test.h"
#include "_3D_Scene_Single_Light_Test.h"
#include "InputTests.h"

//#include <windows.h>
//#include <string>
//#include <iostream>

//using namespace std;

//#include <BF/Network/Server.h>
//#include <BF/Network/Client.h>

int main()
{
	/*BF::Network::Server server;

	server.Initialize();
	server.Listen();
	server.Accept();*/

	
	/*BF::Network::Client client;

	client.Initialize();
	client.Connect();

	system("PAUSE");*/

	//BF::Platform::API::Vulkan::VKContext vKContext;

	//BF_LOG_INFO("MAIN FUNCTION");

	//BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Rectangle(800, 250, 1920, 1080), BF::Application::WindowStyle::ResizableWindow), BF::Graphics::API::RenderAPI::OpenGL);

	//BF::Application::SceneManager::AddNewScene(new AndroidTestScene());
	//BF::Application::SceneManager::AddNewScene(new test());

	
	//new3DScene::new3DScene scene;
	//_3D_Scene_Single_Light_Test::_3D_Scene_Single_Light_Test scene;
	//_3DScene_AF_Test::_3DScene_AF_Test scene;
	//_3DScene::_3DScene scene;
	//_2DScene::_2DScene scene;
	//InputTests scene;

	//engine.Run(scene);
	BF::Math::Vector3 v;
	BF::Math::Vector3 v1(10.0f, 20.0f, 30.0f);

	BF_LOG_WARNING("%f %f %f %f", v.x, v.y, v.z);
	BF_LOG_WARNING("%f %f %f %f", v1.x, v1.y, v1.z);

	v = v1;
	BF_LOG_WARNING("%f %f %f %f", v.x, v.y, v.z);

	v.x = 100.0f;
	v.y = 200.0f;
	v.z = 400.0f;

	BF_LOG_WARNING("%f %f %f %f", v.x, v.y, v.z);



	BF::Math::Vector2 vv1(-7, -4);
	BF::Math::Vector2 vv2(17, 6.5);

	BF_LOG_INFO("%f", vv1.Distance(vv2));

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