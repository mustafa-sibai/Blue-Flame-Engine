#pragma once
#include "BF/Platform/Web/WEBWindow.h"
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
		namespace Web
		{
			class BF_API WEBEngineEntryPoint
			{
				private:
					WEBWindow webWindow;
					Graphics::API::Context context;
					Application::Scene* mainScene;

					//--------------------------- THIS TO BE REMOVED AND CHANGED LIKE THE WINDOWS VERION -----------------------
					double totalTime, extra;
					int FPS, FUPS, timesToRunFixedUpdate;
					double elapsedFrameTime;
					//--------------------------- THIS TO BE REMOVED AND CHANGED LIKE THE WINDOWS VERION -----------------------

					double deltaTime;
					double frameRateTarget, frameTimeTarget;

				public:
					enum class State { Initialize, Render, Exit };
					State state;

				public:
					WEBEngineEntryPoint(const WEBWindow& webWindow, Graphics::API::RenderAPI renderAPI);
					~WEBEngineEntryPoint();

					void Run(Application::Scene& mainScene);
					void LimitFrameRate(double limit);

					inline WEBWindow& GetWindow() { return webWindow; }
					inline Graphics::API::Context& GetContext() { return context; }

				private:
					static void FunctionCallBack(void* thisPointer);
					void MainLoop();
			};
		}
	}
}