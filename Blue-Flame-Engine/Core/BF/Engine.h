#pragma once
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/System/SceneManager.h"
#include "BF/System/Log.h"
#include "BF/Common.h"

class BF_API Engine
{
private:
	BF::Application::Window window;
	BF::Graphics::API::Context context;

	float totalTime, extra;
	const float frameRateTarget = 60.0f;
	const float frameTimeTarget = 1000.0f / frameRateTarget;
	int FPS, FUPS, extraTimesToRunFixedUpdate;
	bool runFixedUpdate;

public:
	Engine();
	Engine(const BF::Application::Window& window, const BF::Graphics::API::Context& context);
	~Engine();

	void Run();

	inline const BF::Application::Window& GetWindow() const { return window; }
	inline const BF::Graphics::API::Context& GetContext() const { return context; }
};