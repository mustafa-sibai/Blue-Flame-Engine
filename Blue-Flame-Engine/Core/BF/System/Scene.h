#pragma once
#include "Timer.h"
#include "BF/Application/Window.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Common.h"

class BF_API Scene
{
	friend class Engine;

private:
	BF::System::Timer frameTimer;
	BF::System::Timer frameRateTimer;

	bool run = false;
	bool initialized = false;
	bool loaded = false;
	int fixedUpdateTicks = 0;

public:
	inline void Run() { run = true; }
	inline void Stop() { run = false; }

	inline bool IsRunning() const { return run; }
	
private:
	void SetWindow(const BF::Application::Window& window) { this->window = &window; }
	void SetContext(const BF::Graphics::API::Context& context) { this->context = &context; }
	
protected:
	const BF::Application::Window* window;
	const BF::Graphics::API::Context* context;

protected:
	virtual void Initialize() = 0;
	virtual void Load() = 0;
	virtual void FixedUpdate() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};