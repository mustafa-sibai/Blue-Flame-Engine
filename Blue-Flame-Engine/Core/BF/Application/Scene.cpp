#include "Scene.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Application
	{
		Scene::Scene() :
			run(false), initialized(false), loaded(false), fixedUpdateTicks(0)
		{
		}

		Scene::~Scene()
		{
		}

		void Scene::Initialize()
		{
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
			widgetManager.Initialize();
#endif
		}

		void Scene::Load()
		{
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
			widgetManager.Load();
#endif
		}

		/*void Scene::FixedUpdate()
		{
		}*/

		void Scene::Update()
		{
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
			widgetManager.Update();
#endif
		}

		void Scene::Render()
		{
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
			widgetManager.Render();
#endif
		}
	}
}