#pragma once
#include <vector>
#include "Scene.h"
#include "BF/Common.h"

class BF_API SceneManager
{
private:
	static std::vector<Scene*> scenes;

public:
	static void AddNewScene(Scene* scene);

	//void RemoveScene(const Scene* scene);

	static inline const std::vector<Scene*>& GetScenes() { return scenes; }
	static inline Scene& GetScene(int index) { return *scenes[index]; }
};