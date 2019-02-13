#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined(BFE_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include <vector>
#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/ECS/GameObject.h"
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Scripting/ScriptExecutor.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class SceneManager;

		class BFE_API Scene
		{
			friend class BF::Engine;
			friend class BF::ECS::GameObject;

#ifdef BFE_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINEngineEntryPoint;
#elif defined(BFE_PLATFORM_LINUX)
			friend class BF::Platform::Linux::LXEngineEntryPoint;
#elif defined(BFE_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBEngineEntryPoint;
#elif defined(BFE_PLATFORM_ANDROID)
			friend class BF::Platform::Android::ANDEngineEntryPoint;
#endif

		private:
			BF::Application::App& app;
			std::vector<BF::ECS::GameObject*> gameObjects;

		public:
			Scene(BF::Application::App& app);
			~Scene();

			BF::ECS::GameObject* AddGameObject(BF::ECS::GameObject* gameObject);
			BF::ECS::GameObject* AddGameObject(BF::ECS::GameObject* gameObject, BF::ECS::GameObject* parent);

			void RemoveGameObject(BF::ECS::GameObject* gameObject);

			inline const std::vector<BF::ECS::GameObject*>& GetGameObjects() const { return gameObjects; }
		};
	}
}