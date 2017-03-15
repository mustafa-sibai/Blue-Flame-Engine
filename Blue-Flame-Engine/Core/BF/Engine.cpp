 #include "Engine.h"
#include "BF/Application/SceneManager.h"
#include "BF/System/Log.h"

namespace BF
{
	using namespace BF::Graphics::API;
	using namespace BF::Application;

#ifdef BF_PLATFORM_WINDOWS
	using namespace BF::Platform::Windows;
#elif BF_PLATFORM_WEBGL
	using namespace BF::Platform::WebGL;
#endif

#ifdef BF_PLATFORM_WINDOWS
	WINEngineEntryPoint* Engine::winEngineEntryPoint = nullptr;
#elif BF_PLATFORM_WEBGL
	WEBEngineEntryPoint* Engine::webEngineEntryPoint = nullptr;
#endif

	Engine::Engine(const Window& window, RenderAPI renderAPI)
	{
#ifdef BF_PLATFORM_WINDOWS
		Engine::winEngineEntryPoint = new WINEngineEntryPoint(WINWindow(window.title, window.rectangle, window.style), renderAPI);
#elif BF_PLATFORM_WEBGL
		Engine::webEngineEntryPoint = new WEBEngineEntryPoint(WEBWindow(window.title, window.rectangle, window.style), renderAPI);
#endif
		BF_LOG_INFO("Blue Flame Engine v%d.%d.%d", BF_ENGINE_MAJOR_VERSION, BF_ENGINE_MINOR_VERSION, BF_ENGINE_PATCH_VERSION);
	}

	Engine::~Engine()
	{
#ifdef BF_PLATFORM_WINDOWS
		delete Engine::winEngineEntryPoint;
#elif BF_PLATFORM_WEBGL
		delete Engine::webEngineEntryPoint;
#endif
	}

	void Engine::Run()
	{
#ifdef BF_PLATFORM_WINDOWS
		winEngineEntryPoint->Run();
#elif BF_PLATFORM_WEBGL
		webEngineEntryPoint->Run();
#endif
	}
}