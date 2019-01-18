#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
#elif defined (BFE_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXEngineEntryPoint.h"
#elif defined (BFE_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBEngineEntryPoint.h"
#elif defined (BFE_PLATFORM_ANDROID)
	#include "BF/Platform/Android/ANDEngineEntryPoint.h"
#endif

#include "BF/Common.h"

#define BFE_ENGINE_MAJOR_VERSION 0
#define BFE_ENGINE_MINOR_VERSION 190118
#define BFE_ENGINE_PATCH_VERSION 0

namespace BF
{
#if defined (BFE_PLATFORM_ANDROID) || defined (BFE_PLATFORM_LINUX)
	namespace Application
	{
		class Scene;
	}
#endif

	class BFE_API Engine
	{
		private:
#ifdef BFE_PLATFORM_WINDOWS
			friend class Platform::Windows::WINEngineEntryPoint;
			friend class Platform::Windows::WINWindow;
			static Platform::Windows::WINEngineEntryPoint* winEngineEntryPoint;
#elif defined (BFE_PLATFORM_LINUX)
			friend class Platform::Linux::LXEngineEntryPoint;
			static Platform::Linux::LXEngineEntryPoint* lxEngineEntryPoint;
#elif defined (BFE_PLATFORM_WEB)
			friend class Platform::Web::WEBEngineEntryPoint;
			static Platform::Web::WEBEngineEntryPoint* webEngineEntryPoint;
#elif defined (BFE_PLATFORM_ANDROID)
			friend class Platform::Android::ANDEngineEntryPoint;
			static Platform::Android::ANDEngineEntryPoint* andEngineEntryPoint;
#endif

			enum class State { None, Initialize, Render, Exit };
			static State state;

		public:
			Engine(const BF::Application::Window& window, Graphics::API::RenderAPI renderAPI);
			~Engine();

			void Run(Application::App& app);
			static void Exit();

			static void LimitFrameRate(double limit);

#ifdef BFE_PLATFORM_WINDOWS
			static inline double GetDeltaTime() { return winEngineEntryPoint->GetDeltaTime(); }
			static inline Platform::Windows::WINWindow& GetWindow() { return winEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return winEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_LINUX)
			static inline Platform::Linux::LXWindow& GetWindow() { return lxEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return lxEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_WEB)
			static inline Platform::Web::WEBWindow& GetWindow() { return webEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return webEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_ANDROID)
			static inline Platform::Android::ANDWindow& GetWindow() { return andEngineEntryPoint->GetWindow(); }
			static inline Graphics::API::Context& GetContext() { return andEngineEntryPoint->GetContext(); }
#endif
	};
}