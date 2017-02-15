#pragma once
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

#define BF_ENGINE_MAJOR_VERSION 0
#define BF_ENGINE_MINOR_VERSION 170202
#define BF_ENGINE_PATCH_VERSION 0

namespace BF
{
	class BF_API Engine
	{
		private:
			static Application::Window window;
			static Graphics::API::Context context;

			double totalTime, extra;
			const float frameRateTarget = 60.0f;
			const float frameTimeTarget = 1000.0f / frameRateTarget;
			int FPS, FUPS, timesToRunFixedUpdate;
			double elapsedFrameTime;

		public:
			enum class State { Initialize, Render, Exit };
			static State state;

		public:
			Engine(Application::Window window, Graphics::API::RenderAPI renderAPI);
			~Engine();

			void Run();

			static inline Application::Window& GetWindow() { return window; }
			static inline Graphics::API::Context& GetContext() { return context; }
	};
}