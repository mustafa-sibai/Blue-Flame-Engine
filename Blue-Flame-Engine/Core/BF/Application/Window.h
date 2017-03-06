#pragma once
#include <string>

#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINWindow.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/Linux/LXWindow.h"
#elif BF_PLATFORM_WEBGL
	#include "BF/Platform/WebGL/WEBWindow.h"
#elif BF_PLATFORM_ANDROID
	#include "BF/Platform/Android/AWindow.h"
#endif

#include "WindowStyle.h"

namespace BF
{
	namespace Application
	{
		class BF_API Window : public
#ifdef BF_PLATFORM_WINDOWS
			Platform::Windows::WINWindow
#elif BF_PLATFORM_LINUX
			Platform::Linux::LXWindow
#elif BF_PLATFORM_WEBGL
			Platform::WebGL::WEBWindow
#elif BF_PLATFORM_ANDROID
			Platform::Android::AWindow
#endif
		{
			public:
				Window(const std::string& title, const Math::Rectangle& rectangle, BF::Application::WindowStyle style);
				~Window();

				void Initialize();
				void Update();
				bool IsOpen();
		};
	}
}