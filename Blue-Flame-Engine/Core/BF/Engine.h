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
		friend class BF::Platform::Windows::WINEngineEntryPoint;
		friend class BF::Platform::Windows::WINWindow;
		static Platform::Windows::WINEngineEntryPoint* winEngineEntryPoint;
#elif defined (BFE_PLATFORM_LINUX)
		friend class BF::Platform::Linux::LXEngineEntryPoint;
		static BF::Platform::Linux::LXEngineEntryPoint* lxEngineEntryPoint;
#elif defined (BFE_PLATFORM_WEB)
		friend class BF::Platform::Web::WEBEngineEntryPoint;
		static BF::Platform::Web::WEBEngineEntryPoint* webEngineEntryPoint;
#elif defined (BFE_PLATFORM_ANDROID)
		friend class BF::Platform::Android::ANDEngineEntryPoint;
		static BF::Platform::Android::ANDEngineEntryPoint* andEngineEntryPoint;
#endif

		enum class State { None, Initialize, Render, Exit };
		static State state;

	public:
		Engine(const BF::Application::Window& window, BF::Graphics::API::RenderAPI renderAPI);
		~Engine();

		void Run(BF::Application::App& app);
		static void Exit();

		static void LimitFrameRate(double limit);

#ifdef BFE_PLATFORM_WINDOWS
		static inline BF::Platform::Windows::WINWindow& GetWindow() { return winEngineEntryPoint->GetWindow(); }
		static inline BF::Graphics::API::Context& GetContext() { return winEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_LINUX)
		static inline BF::Platform::Linux::LXWindow& GetWindow() { return lxEngineEntryPoint->GetWindow(); }
		static inline BF::Graphics::API::Context& GetContext() { return lxEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_WEB)
		static inline BF::Platform::Web::WEBWindow& GetWindow() { return webEngineEntryPoint->GetWindow(); }
		static inline BF::Graphics::API::Context& GetContext() { return webEngineEntryPoint->GetContext(); }
#elif defined (BFE_PLATFORM_ANDROID)
		static inline BF::Platform::Android::ANDWindow& GetWindow() { return andEngineEntryPoint->GetWindow(); }
		static inline BF::Graphics::API::Context& GetContext() { return andEngineEntryPoint->GetContext(); }
#endif
	};
}