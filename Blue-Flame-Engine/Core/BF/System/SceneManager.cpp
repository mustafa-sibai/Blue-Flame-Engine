#include "SceneManager.h"

std::vector<Scene*> SceneManager::scenes;

void SceneManager::AddNewScene(Scene* scene)
{
	scenes.push_back(scene);
}