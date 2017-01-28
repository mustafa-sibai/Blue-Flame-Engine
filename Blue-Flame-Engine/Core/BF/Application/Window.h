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

namespace BF
{
	namespace Application
	{
		class BF_API Window : public
#ifdef BF_PLATFORM_WINDOWS
			Platform::Windows::WINWindow
#elif BF_PLATFORM_LINUX
			Platform::Linux::LXWindow;
#elif BF_PLATFORM_WEBGL
			Platform::WebGL::WEBWindow;
#elif BF_PLATFORM_ANDROID
			Platform::Android::AWindow;
#endif
		{
			public:
				Window(const std::string& title, unsigned short positionX, unsigned short positionY, unsigned short width, unsigned short height, Application::WindowStyle style);
				~Window();

				void Initialize();
				void Update();
				bool IsOpen();
		};
	}
}