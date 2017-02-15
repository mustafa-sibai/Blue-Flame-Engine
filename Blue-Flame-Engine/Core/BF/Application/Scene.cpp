#include "Scene.h"
#include "BF/System/Log.h"

namespace BF
{
	namespace Application
	{
		void Scene::Initialize()
		{
			widgetManager.Initialize();
		}

		void Scene::Load()
		{
			widgetManager.Load();
		}

		void Scene::FixedUpdate()
		{
		}

		void Scene::Update()
		{
			widgetManager.Update();
		}

		void Scene::Render()
		{
			widgetManager.Render();
		}
	}
}