#pragma once
#include <vector>
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API SceneManager
		{
			private:
				static std::vector<Scene*> scenes;
				static Scene* currentScene;

			public:
				static void AddNewScene(Scene* scene);
				static void LoadScene(int index);

				static inline const std::vector<Scene*>& GetScenes() { return scenes; }
				static inline Scene& GetScene(int index) { return *scenes[index]; }
				static inline Scene& GetCurrentScene() { return *currentScene; }
		};
	}
}