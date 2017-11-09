#include "SceneManager.h"

namespace BF
{
	namespace Application
	{
		std::vector<Scene*> SceneManager::scenes;
		Scene* SceneManager::currentScene = nullptr;

		void SceneManager::AddNewScene(Scene* scene)
		{
			scenes.emplace_back(scene);
		}

		void SceneManager::LoadScene(int index)
		{
			currentScene = scenes[index];
		}
	}
}