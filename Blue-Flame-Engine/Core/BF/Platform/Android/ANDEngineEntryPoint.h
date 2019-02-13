#pragma once
#include "BF/Platform/Android/ANDWindow.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class Scene;
	}

	namespace Platform
	{
		namespace Android
		{
			class BFE_API ANDEngineEntryPoint
			{
				private:
					ANDWindow andWindow;
					Graphics::API::Context context;

					double totalTime, extra;
					int FPS, FUPS, timesToRunFixedUpdate;
					double elapsedFrameTime;

				public:
					ANDEngineEntryPoint(const ANDWindow& andWindow, Graphics::API::RenderAPI renderAPI);
					~ANDEngineEntryPoint();

					void Run(Application::Scene& mainScene);

					inline ANDWindow& GetWindow() { return andWindow; }
					inline Graphics::API::Context& GetContext() { return context; }
			};
		}
	}
}