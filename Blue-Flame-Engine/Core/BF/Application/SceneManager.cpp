#include "SceneManager.h"
#include "BF/System/Debug.h"
#include "BF/IO/SceneLoader.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::IO;

		SceneManager::SceneManager(BF::Application::Layers::LayerManager& layerManager) :
			layerManager(layerManager), currentScene(nullptr)
		{
		}

		SceneManager::~SceneManager()
		{
		}

		void SceneManager::AddScene()
		{
			scenes.emplace_back(new Scene(layerManager));
		}

		Scene* SceneManager::LoadScene(int index)
		{
			if (index > scenes.size() - 1)
			{
				BFE_LOG_ERROR("Could not load scene number " + to_string(index) + ". The current number of scenes added to the list is " + to_string(scenes.size() - 1), "");
				return nullptr;
			}

			currentScene = scenes[index];
			currentScene->Initialize();
			currentScene->Load();
			return currentScene;
		}
	}
}