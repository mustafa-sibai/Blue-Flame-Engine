#include "App.h"
#include "BF/Application/SceneManager.h"

namespace BF
{
	namespace Application
	{
		App::App() :
			initialized(false), loaded(false), fixedUpdateTicks(0)
		{
		}

		App::~App()
		{
		}

		void App::Initialize()
		{
			BF::Application::SceneManager::GetScenes()[0]->Initialize();
		}

		void App::Load()
		{
			BF::Application::SceneManager::GetScenes()[0]->Load();
		}

		/*void Scene::FixedUpdate()
		{
		}*/

		void App::Update()
		{
			BF::Application::SceneManager::GetScenes()[0]->Update();
		}

		void App::Render()
		{
			BF::Application::SceneManager::GetScenes()[0]->Render();
		}
	}
}