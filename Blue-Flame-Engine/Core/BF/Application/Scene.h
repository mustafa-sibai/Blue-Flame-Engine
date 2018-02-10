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

#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
/*#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
	#include "BF/Graphics/GUI/WidgetManager.h"
#endif*/
#include "BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h"
#include "BF/Application/Layers/LayerManager.h"
#include "BF/Application/GameObject.h"
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
				BF::Graphics::Renderers::SpriteRenderer spriteRenderer;

/*
#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				BF::Graphics::GUI::WidgetManager widgetManager;
#endif*/
				bool initialized;
				bool loaded;
				int fixedUpdateTicks;

				GameObject* rootGameObject;

			public:
				Scene();
				~Scene();

/*#if defined(BF_PLATFORM_WINDOWS) || defined(BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				inline BF::Graphics::GUI::WidgetManager& GetWidgetManager() { return widgetManager; }
#endif*/

			public:
				void Initialize(BF::Application::Layers::LayerManager& layerManager);
				void Load();
				//void FixedUpdate();
				void Update();
				void Render();

				//GameNode* Instantiate(const std::string& name, GameNode* gameNode, GameNode* parent);

				inline GameObject& GetRootGameNode() { return *rootGameObject; }

			private:
				void RenderNode(GameObject* gameObject);
		};
	}
}