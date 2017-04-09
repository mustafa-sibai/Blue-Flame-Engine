#pragma once
#include "WEBWindow.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace WebGL
		{
			class BF_API WEBEngineEntryPoint
			{
				private:
					WEBWindow webWindow;
					Graphics::API::Context context;

					double totalTime, extra;
					int FPS, FUPS, timesToRunFixedUpdate;
					double elapsedFrameTime;

				public:
					enum class State { Initialize, Render, Exit };
					State state;

				public:
					WEBEngineEntryPoint(const WEBWindow& webWindow, Graphics::API::RenderAPI renderAPI);
					~WEBEngineEntryPoint();

					void Run();

					inline WEBWindow& GetWindow() { return webWindow; }
					inline Graphics::API::Context& GetContext() { return context; }

				private:
					static void FunctionCallBack(void* thisPointer);
					void MainLoop();
			};
		}
	}
}