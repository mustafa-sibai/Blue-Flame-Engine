 #include "Engine.h"
#include "BF/System/Log.h"

namespace BF
{
	using namespace BF::Graphics::API;
	using namespace BF::Application;

#ifdef BF_PLATFORM_WINDOWS
	using namespace BF::Platform::Windows;
#elif defined (BF_PLATFORM_LINUX)
	using namespace BF::Platform::Linux;
#elif defined (BF_PLATFORM_WEB)
	using namespace BF::Platform::Web;
#elif defined (BF_PLATFORM_ANDROID)
	using namespace BF::Platform::Android;
#endif

#ifdef BF_PLATFORM_WINDOWS
	WINEngineEntryPoint* Engine::winEngineEntryPoint = nullptr;
#elif defined (BF_PLATFORM_LINUX)
	LXEngineEntryPoint* Engine::lxEngineEntryPoint = nullptr;
#elif defined (BF_PLATFORM_WEB)
	WEBEngineEntryPoint* Engine::webEngineEntryPoint = nullptr;
#elif defined (BF_PLATFORM_ANDROID)
	ANDEngineEntryPoint* Engine::andEngineEntryPoint = nullptr;
#endif

	Engine::Engine(const Window& window, RenderAPI renderAPI)
	{
#ifdef BF_PLATFORM_WINDOWS
		Engine::winEngineEntryPoint = new WINEngineEntryPoint(WINWindow(window.GetTitle(), window.GetRectangle(), window.GetStyle()), renderAPI);
#elif defined (BF_PLATFORM_LINUX)
		Engine::lxEngineEntryPoint = new LXEngineEntryPoint(LXWindow(window.GetTitle(), window.GetRectangle(), window.GetStyle()), renderAPI);
#elif defined (BF_PLATFORM_WEB)
		Engine::webEngineEntryPoint = new WEBEngineEntryPoint(WEBWindow(window.GetTitle(), window.GetRectangle(), window.GetStyle()), renderAPI);
#elif defined (BF_PLATFORM_ANDROID)
		Engine::andEngineEntryPoint = new ANDEngineEntryPoint(ANDWindow(window.GetTitle(), window.GetRectangle(), window.GetStyle()), renderAPI);
#endif
		BF_LOG_INFO("Blue Flame Engine v%d.%d.%d", BF_ENGINE_MAJOR_VERSION, BF_ENGINE_MINOR_VERSION, BF_ENGINE_PATCH_VERSION);
	}

	Engine::~Engine()
	{
#ifdef BF_PLATFORM_WINDOWS
		delete Engine::winEngineEntryPoint;
#elif defined (BF_PLATFORM_LINUX)
		delete Engine::lxEngineEntryPoint;
#elif defined (BF_PLATFORM_WEB)
		delete Engine::webEngineEntryPoint;
#elif defined (BF_PLATFORM_ANDROID)
		delete Engine::andEngineEntryPoint;
#endif
	}

	void Engine::Run(Scene& mainScene)
	{
#ifdef BF_PLATFORM_WINDOWS
		winEngineEntryPoint->Run(mainScene);
#elif defined (BF_PLATFORM_LINUX)
		lxEngineEntryPoint->Run(mainScene);
#elif defined (BF_PLATFORM_WEB)
		webEngineEntryPoint->Run(mainScene);
#elif defined (BF_PLATFORM_ANDROID)
		andEngineEntryPoint->Run(mainScene);
#endif
	}

	void Engine::LimitFrameRate(double limit)
	{
#ifdef BF_PLATFORM_WINDOWS
		winEngineEntryPoint->LimitFrameRate(limit);
#elif defined (BF_PLATFORM_LINUX)
		lxEngineEntryPoint->LimitFrameRate(limit);
#elif defined (BF_PLATFORM_WEB)
		webEngineEntryPoint->LimitFrameRate(limit);
#elif defined (BF_PLATFORM_ANDROID)
		andEngineEntryPoint->LimitFrameRate(limit);
#endif
	}
}