#pragma once
#include "BF/Engine.h"
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
//#include "BF/Graphics/GUI/WidgetManager.h"
#include "BF/System/Timer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API Scene
		{
			friend class BF::Engine;

			private:
				System::Timer frameTimer;
				System::Timer frameRateTimer;
				//Graphics::GUI::WidgetManager widgetManager;
				bool run = false;
				bool initialized = false;
				bool loaded = false;
				int fixedUpdateTicks = 0;

			public:
				inline void Run() { run = true; }
				inline void Stop() { run = false; }

				inline bool IsRunning() const { return run; }
				//inline Graphics::GUI::WidgetManager& GetWidgetManager() { return widgetManager; }

			protected:
				virtual void Initialize() = 0;
				virtual void Load() = 0;
				virtual void FixedUpdate() = 0;
				virtual void Update() = 0;
				virtual void Render() = 0;
		};
	}
}