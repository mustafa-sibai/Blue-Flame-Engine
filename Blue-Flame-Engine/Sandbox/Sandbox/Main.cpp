#include <BF/BlueFlame.h>

//#include "_2DScene.h"
//#include "_3DScene.h"
//#include "new3DScene.h"
//#include "_3DScene_AF_Test.h"
//#include "_3D_Scene_Single_Light_Test.h"
//#include "InputTests.h"
//#include "GUIScene.h"
//#include "PhysicsScene.h"
#include "TestApp.h"

int main()
{
#ifdef BF_NO_NET
	BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Rectangle(500, 500, 1280, 720), BF::Application::WindowStyle::ResizableWindow), BF::Graphics::API::RenderAPI::OpenGL);

	//BF::Application::SceneManager::AddNewScene(new AndroidTestScene());
	//BF::Application::SceneManager::AddNewScene(new test());

	//new3DScene::new3DScene scene;
	//_3D_Scene_Single_Light_Test::_3D_Scene_Single_Light_Test scene;
	//_3DScene_AF_Test::_3DScene_AF_Test scene;
	//_3DScene::_3DScene scene;
	//_2DScene::_2DScene scene;
	//PhysicsScene::PhysicsScene scene;
	TestApp::TestApp testApp;
	//InputTests scene;

	engine.Run(testApp);
#elif defined (BF_CLIENT)
	BF::Network::Client client;

	client.Initialize();
	client.Connect();

	system("PAUSE");
#elif defined (BF_SERVER)
	BF::Network::Server server;

	server.Initialize();
	server.Listen();
	server.Accept();

	system("PAUSE");
#endif

	/*
		TCHAR  buffer[MAX_PATH];
		GetModulefilename(NULL, buffer, MAX_PATH);

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