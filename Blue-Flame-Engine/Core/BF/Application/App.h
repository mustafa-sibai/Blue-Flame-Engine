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

#include "BF/Engine.h"
#include "BF/Application/Window.h"
//#include "BF/Application/Layers/LayerManager.h"
//#include "BF/Graphics/GUI/StyleSheet.h"
//#include "BF/Application/SceneManager.h"
#include "BF/Graphics/Renderers/RenderPipeline.h"
#include "BF/Graphics/CameraManager.h"
#include "BF/Application/Scene.h"
#include "BF/Graphics/API/Context.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BFE_API App
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
			//SceneManager sceneManager;
			//BF::Application::Layers::LayerManager layerManager;

			Scene* mainScene;

			BF::Graphics::CameraManager cameraManager;
			BF::Graphics::ConstantBufferManager constantBufferManager;
			BF::Graphics::Renderers::RenderPipeline renderPipeline;
			BF::Scripting::ScriptExecutor scriptExecutor;

			BF::System::Timer frameTimer;
			BF::System::Timer fixedUpdateTimer;
			BF::System::Timer frameRateTimer;

			bool initialized;
			bool loaded;
			int fixedUpdateTicks;

			//BF::Graphics::GUI::StyleSheet styleSheet;

		public:
			App();
			virtual ~App();

			virtual void Initialize();
			virtual void Load();
			virtual void PostLoad();
			virtual void Update();
			virtual void Render();

			void RunScene(Scene& scene);

			//inline SceneManager& GetSceneManager() { return sceneManager; }
			//inline BF::Application::Layers::LayerManager& GetLayerManager() { return layerManager; }
		};
	}
}