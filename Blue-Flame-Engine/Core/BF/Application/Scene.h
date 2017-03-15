#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif BF_PLATFORM_WEBGL
	#include "BF/Platform/WebGL/WEBEngineEntryPoint.h"
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
#elif BF_PLATFORM_WEBGL
			friend class BF::Platform::WebGL::WEBEngineEntryPoint;
#endif

			private:
				System::Timer frameTimer;
				System::Timer frameRateTimer;
				Graphics::GUI::WidgetManager widgetManager;
				bool run = false;
				bool initialized = false;
				bool loaded = false;
				int fixedUpdateTicks = 0;

			public:
				inline void Run() { run = true; }
				inline void Stop() { run = false; }

				inline bool IsRunning() const { return run; }
				inline Graphics::GUI::WidgetManager& GetWidgetManager() { return widgetManager; }

			protected:
				virtual void Initialize();
				virtual void Load();
				virtual void FixedUpdate();
				virtual void Update();
				virtual void Render();
		};
	}
}