#pragma once
#include <vector>
#include "Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API SceneManager
		{
			private:
				static std::vector<Scene*> scenes;

			public:
				static void AddNewScene(Scene* scene);

				static inline const std::vector<Scene*>& GetScenes() { return scenes; }
				static inline Scene& GetScene(int index) { return *scenes[index]; }
		};
	}
}