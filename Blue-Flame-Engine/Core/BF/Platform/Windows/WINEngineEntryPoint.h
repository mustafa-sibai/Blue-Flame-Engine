#pragma once
#include "BF/Platform/Windows/WINWindow.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class App;
	}

	namespace Platform
	{
		namespace Windows
		{
			class BF_API WINEngineEntryPoint
			{
				private:
					WINWindow winWindow;
					Graphics::API::Context context;

					double deltaTime;
					double frameRateTarget, frameTimeTarget;
					unsigned int FPS;

				public:
					WINEngineEntryPoint(const WINWindow& winWindow, Graphics::API::RenderAPI renderAPI);
					~WINEngineEntryPoint();

					void Run(Application::App& app);
					void LimitFrameRate(double limit);

					inline double GetDeltaTime() const { return deltaTime; }
					inline WINWindow& GetWindow() { return winWindow; }
					inline Graphics::API::Context& GetContext() { return context; }
			};
		}
	}
}