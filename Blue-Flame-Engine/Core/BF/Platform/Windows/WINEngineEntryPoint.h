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
			class BFE_API WINEngineEntryPoint
			{
			private:
				WINWindow winWindow;
				BF::Graphics::API::Context context;

				double deltaTime;
				double frameRateTarget, frameTimeTarget;
				unsigned int FPS;

			public:
				WINEngineEntryPoint(const WINWindow& winWindow, BF::Graphics::API::RenderAPI renderAPI);
				~WINEngineEntryPoint();

				void Run(BF::Application::App& app);
				void LimitFrameRate(double limit);

				inline WINWindow& GetWindow() { return winWindow; }
				inline BF::Graphics::API::Context& GetContext() { return context; }
			};
		}
	}
}