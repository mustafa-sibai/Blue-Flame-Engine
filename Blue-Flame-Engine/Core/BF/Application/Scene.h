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
/*#if defined(BFE_PLATFORM_WINDOWS) || defined(BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
	#include "BF/Graphics/GUI/WidgetManager.h"
#endif*/
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
				BF::Scripting::ScriptExecutor scriptExecutor;
				std::vector<BF::ECS::GameObject*> gameObjects;

			public:
				BF::ECS::GameObject* AddGameObject(BF::ECS::GameObject* gameObject);
				BF::ECS::GameObject* AddGameObject(BF::ECS::GameObject* gameObject, BF::ECS::GameObject* parent);

				void RemoveGameObject(BF::ECS::GameObject* gameObject);
/*
#if defined(BFE_PLATFORM_WINDOWS) || defined(BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				BF::Graphics::GUI::WidgetManager widgetManager;
#endif*/
		private:
				bool initialized;
				bool loaded;
				int fixedUpdateTicks;

				//GameObject* rootGameObject;

			public:
				Scene(BF::Application::App& app);
				~Scene();

/*#if defined(BFE_PLATFORM_WINDOWS) || defined(BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				inline BF::Graphics::GUI::WidgetManager& GetWidgetManager() { return widgetManager; }
#endif*/

			public:
				void Initialize(/*BF::Application::Layers::LayerManager& layerManager*/);
				void Load();
				void PostLoad();
				//void FixedUpdate();
				void Update();
				void Render();

				//GameNode* Instantiate(const std::string& name, GameNode* gameNode, GameNode* parent);

				inline const std::vector<BF::ECS::GameObject*>& GetGameObjects() const { return gameObjects; }
				//inline GameObject& GetRootGameNode() { return *rootGameObject; }

			private:
				//void RenderNode(GameObject* gameObject);
		};
	}
}