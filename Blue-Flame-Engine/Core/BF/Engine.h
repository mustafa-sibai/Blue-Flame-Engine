#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif BF_PLATFORM_WEBGL
	#include "BF/Platform/WebGL/WEBEngineEntryPoint.h"
#endif

#include "BF/Common.h"

#define BF_ENGINE_MAJOR_VERSION 0
#define BF_ENGINE_MINOR_VERSION 170314
#define BF_ENGINE_PATCH_VERSION 0

namespace BF
{
	class BF_API Engine
	{
		public:
#ifdef BF_PLATFORM_WINDOWS
			static Platform::Windows::WINEngineEntryPoint* winEngineEntryPoint;
#elif BF_PLATFORM_WEBGL
			static Platform::WebGL::WEBEngineEntryPoint* webEngineEntryPoint;
#endif
		public:
			Engine(const Application::Window& window, Graphics::API::RenderAPI renderAPI);
			~Engine();

			void Run();

#ifdef BF_PLATFORM_WINDOWS
			static inline Platform::Windows::WINWindow& GetWindow() { return winEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return winEngineEntryPoint->GetContext(); }
#elif BF_PLATFORM_WEBGL
			static inline Platform::WebGL::WEBWindow& GetWindow() { return webEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return webEngineEntryPoint->GetContext(); }
#endif
	};
}