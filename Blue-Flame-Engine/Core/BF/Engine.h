#pragma once
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

namespace BF
{
	class BF_API Engine
	{
	private:
		static BF::Application::Window window;
		static BF::Graphics::API::Context context;

		double totalTime, extra;
		const float frameRateTarget = 60.0f;
		const float frameTimeTarget = 1000.0f / frameRateTarget;
		int FPS, FUPS, timesToRunFixedUpdate;
		double elapsedFrameTime;

	public:
		enum class State { Initialize, Render };
		static State state;

	public:
		Engine(BF::Application::Window window, BF::Graphics::API::RenderAPI renderAPI);
		~Engine();

		void Run();

		static inline BF::Application::Window& GetWindow() { return window; }
		static inline BF::Graphics::API::Context& GetContext() { return context; }
	};
}