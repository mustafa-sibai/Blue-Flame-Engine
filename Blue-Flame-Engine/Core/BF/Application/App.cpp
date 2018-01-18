#include "App.h"

namespace BF
{
	namespace Application
	{
		App::App() :
			initialized(false), loaded(false), fixedUpdateTicks(0), mainScene(nullptr)//, sceneManager(layerManager)
		{
		}

		App::~App()
		{
		}

		void App::Initialize()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Initialize();
		}

		void App::Load()
		{
			//BF::Application::SceneManager::GetScenes()[0]->Load();
		}

		void App::Update()
		{
			if (mainScene != nullptr)
				mainScene->Update();

			layerManager.Update();
			//sceneManager.GetCurrentScene().Update();
			//BF::Application::SceneManager::GetScenes()[0]->Update();
		}

		void App::Render()
		{
			if(mainScene != nullptr)
				mainScene->Render();

			//sceneManager.GetCurrentScene().Render();
			//BF::Application::SceneManager::GetScenes()[0]->Render();
		}

		void App::SetMainScene(Scene& scene)
		{
			mainScene = &scene;
			mainScene->Initialize(layerManager);
			mainScene->Load();
		}
	}
}