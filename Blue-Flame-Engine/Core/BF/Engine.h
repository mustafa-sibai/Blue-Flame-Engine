#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined (BF_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined (BF_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined (BF_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include "BF/Common.h"

#define BF_ENGINE_MAJOR_VERSION 0
#define BF_ENGINE_MINOR_VERSION 170513
#define BF_ENGINE_PATCH_VERSION 0

namespace BF
{
#if defined (BF_PLATFORM_ANDROID) || defined (BF_PLATFORM_LINUX)
	namespace Application
	{
		class Scene;
	}
#endif

	class BF_API Engine
	{
		public:
#ifdef BF_PLATFORM_WINDOWS
			static Platform::Windows::WINEngineEntryPoint* winEngineEntryPoint;
#elif defined (BF_PLATFORM_LINUX)
			static Platform::Linux::LXEngineEntryPoint* lxEngineEntryPoint;
#elif defined (BF_PLATFORM_WEB)
			static Platform::Web::WEBEngineEntryPoint* webEngineEntryPoint;
#elif defined (BF_PLATFORM_ANDROID)
			static Platform::Android::ANDEngineEntryPoint* andEngineEntryPoint;
#endif
		public:
			Engine(const Application::Window& window, Graphics::API::RenderAPI renderAPI);
			~Engine();

			void Run(Application::Scene& mainScene);

			static void LimitFrameRate(double limit);

#ifdef BF_PLATFORM_WINDOWS
			static inline double GetDeltaTime() { return winEngineEntryPoint->GetDeltaTime(); }
			static inline Platform::Windows::WINWindow& GetWindow() { return winEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return winEngineEntryPoint->GetContext(); }
#elif defined (BF_PLATFORM_LINUX)
			static inline Platform::Linux::LXWindow& GetWindow() { return lxEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return lxEngineEntryPoint->GetContext(); }
#elif defined (BF_PLATFORM_WEB)
			static inline Platform::Web::WEBWindow& GetWindow() { return webEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return webEngineEntryPoint->GetContext(); }
#elif defined (BF_PLATFORM_ANDROID)
			static inline Platform::Android::ANDWindow& GetWindow() { return andEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return andEngineEntryPoint->GetContext(); }
#endif
	};
}