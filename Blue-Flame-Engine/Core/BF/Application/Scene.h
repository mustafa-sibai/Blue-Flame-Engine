#pragma once

#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined(BF_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined(BF_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined(BF_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include <vector>
#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/ECS/GameObject.h"
/*#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
	#include "BF/Graphics/GUI/WidgetManager.h"
#endif*/
#include "BF/Graphics/Camera.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h"
#include "BF/Graphics/Renderers/ForwardRenderer/ForwardRenderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class SceneManager;

		class BF_API Scene
		{
			friend class BF::Engine;

#ifdef BF_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINEngineEntryPoint;
#elif defined(BF_PLATFORM_LINUX)
			friend class BF::Platform::Linux::LXEngineEntryPoint;
#elif defined(BF_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBEngineEntryPoint;
#elif defined(BF_PLATFORM_ANDROID)
			friend class BF::Platform::Android::ANDEngineEntryPoint;
#endif

			private:
				//BF::Graphics::Renderers::SpriteRenderer spriteRenderer;
				BF::Graphics::Renderers::ForwardRenderer forwardRenderer;
				std::vector<BF::ECS::GameObject*> gameObjects;

			public:
				BF::ECS::GameObject* AddGameObject(BF::ECS::GameObject* gameObject);
				BF::ECS::Component* AddComponentToGameObject(BF::ECS::GameObject* gameObject, BF::ECS::Component* component);

				void RemoveGameObject(BF::ECS::GameObject* gameObject);
				void RemoveComponentFromGameObject(BF::ECS::GameObject* gameObject, BF::ECS::Component* component);
/*
#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				BF::Graphics::GUI::WidgetManager widgetManager;
#endif*/
		private:
				bool initialized;
				bool loaded;
				int fixedUpdateTicks;

				//GameObject* rootGameObject;

			public:
				Scene(BF::Graphics::Camera& camera);
				~Scene();

/*#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
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