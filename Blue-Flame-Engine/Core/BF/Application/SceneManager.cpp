#include "SceneManager.h"
#include "BF/System/Debug.h"
#include "BF/IO/SceneLoader.h"

namespace BF
{
	namespace Application
	{
		using namespace std;
		using namespace BF::IO;
		using namespace BF::Graphics::Renderers;

		std::vector<Scene*> SceneManager::scenes;
		Scene* SceneManager::currentScene = nullptr;


		void SceneManager::AddNewScene(Scene* scene)
		{
			scenes.emplace_back(scene);
		}

		void SceneManager::LoadScene(int index)
		{
			if (index > scenes.size() - 1)
			{
				BF_LOG_ERROR("Could not load scene number " + to_string(index) + ". The current number of scenes added to the list is " + to_string(scenes.size() - 1), "");
				return;
			}

			currentScene = scenes[index];
			currentScene->Initialize();
			currentScene->Load();
		}
	}
}