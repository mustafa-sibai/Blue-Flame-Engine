#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined(BF_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined(BF_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Graphics/GUI/WidgetManager.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API Scene
		{
			friend class BF::Engine;

#ifdef BF_PLATFORM_WINDOWS
				friend class BF::Platform::Windows::WINEngineEntryPoint;
#elif defined(BF_PLATFORM_WEB)
				friend class BF::Platform::Web::WEBEngineEntryPoint;
#elif defined(BF_PLATFORM_ANDROID)
			friend class BF::Platform::Android::ANDEngineEntryPoint;
#endif

			private:
				System::Timer frameTimer;
				System::Timer frameRateTimer;
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
				Graphics::GUI::WidgetManager widgetManager;
#endif
				bool run;
				bool initialized;
				bool loaded;
				int fixedUpdateTicks;

			public:
				Scene();
				~Scene();

				inline void Run() { run = true; }
				inline void Stop() { run = false; }

				inline bool IsRunning() const { return run; }
#if defined(BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_WEB)
				inline Graphics::GUI::WidgetManager& GetWidgetManager() { return widgetManager; }
#endif

			protected:
				virtual void Initialize();
				virtual void Load();
				virtual void FixedUpdate();
				virtual void Update();
				virtual void Render();
		};
	}
}