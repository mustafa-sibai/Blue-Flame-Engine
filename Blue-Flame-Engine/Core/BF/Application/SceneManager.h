#pragma once
#include <vector>
#include "BF/Application/Scene.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BFE_API SceneManager
		{
			private:
				BF::Application::Layers::LayerManager& layerManager;

				std::vector<Scene*> scenes;
				Scene* currentScene;

			public:
				SceneManager(BF::Application::Layers::LayerManager& layerManager);
				~SceneManager();

				void AddScene();
				Scene* LoadScene(int index);

				inline std::vector<Scene*>& GetScenes() { return scenes; }
				inline Scene& GetScene(int index) { return *scenes[index]; }
				inline Scene& GetCurrentScene() { return *currentScene; }
		};
	}
}