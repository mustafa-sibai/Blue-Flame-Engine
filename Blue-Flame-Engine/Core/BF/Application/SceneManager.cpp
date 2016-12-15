#include "SceneManager.h"

namespace BF
{
	namespace Application
	{
		std::vector<Scene*> SceneManager::scenes;

		void SceneManager::AddNewScene(Scene* scene)
		{
			scenes.push_back(scene);
		}
	}
}