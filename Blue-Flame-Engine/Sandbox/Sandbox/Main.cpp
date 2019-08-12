#include <BF/BlueFlame.h>
//#include "_2DScene.h"
//#include "_3DScene.h"
//#include "new3DScene.h"
//#include "_3DScene_AF_Test.h"
//#include "_3D_Scene_Single_Light_Test.h"
//#include "InputTests.h"
//#include "GUIScene.h"
//#include "PhysicsScene.h"
//#include "TestApp.h"
//#include "TerrainTestApp.h"
//#include "ECSTestApp.h"
#include "Forward_Renderer_Test.h"
#include "ECS_Script_Test.h"
#include "Hello_Triangle.h"
#include "IsoMapTest.h"
#include "GUITest.h"
#include "SpriteAnimationTest.h"
#include "CameraViewCullingTest.h"
#include "AstarTest.h"
#include "FontTest.h"
#include "AABBTest.h"

int main()
{
#ifdef BFE_NO_NET
	BF::Engine engine(BF::Application::Window("Blue Flame Engine", BF::Math::Vector2i(150, 150), BF::Math::Vector2i(1280, 720), BF::Application::WindowStyle::ResizableWindow), BF::Graphics::API::RenderAPI::OpenGL);

	//BF::Application::SceneManager::AddNewScene(new AndroidTestScene());
	//BF::Application::SceneManager::AddNewScene(new test());

	//new3DScene::new3DScene app;
	//_3D_Scene_Single_Light_Test::_3D_Scene_Single_Light_Test app;
	//_3DScene_AF_Test::_3DScene_AF_Test app;
	//_3DScenee::_3DScene app;
	//_2DScene::_2DScene app;
	//PhysicsScene::PhysicsScene app;
	//TestApp::TestApp app;
	//TerrainTestApp app;
	//InputTests app;
	//ECS_Script_Test::ECS_Script_Test app;
	//Hello_Triangle::Hello_Triangle app;
	//IsoMapTest::IsoMapTest app;
	//Forward_Renderer_Test::Forward_Renderer_Test app;
	//GUITest::GUITest app;
	//SpriteAnimationTest::SpriteAnimationTest app;
	//CameraViewCullingTest::CameraViewCullingTest app;
	//AstarTest::AstarTest app;
	//FontTest::FontTest app;
	AABBTest::AABBTest app;

	engine.Run(app);
#elif defined (BFE_CLIENT)
	BF::Network::Client client;

	client.Initialize();
	client.Connect();

	system("PAUSE");
#elif defined (BFE_SERVER)
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