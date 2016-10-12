#include "Window.h"

namespace BF
{
	namespace Application
	{
		Window::Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style)
		{
#ifdef BF_PLATFORM_WINDOWS
			winWindow = new Platform::Windows::WINWindow(title, x, y, width, height, style);
#elif BF_PLATFORM_LINUX
			lxWindow = new Platform::Linux::LXWindow(title, x, y, width, height, style);
#elif BF_PLATFORM_WEBGL
			webWindow = new Platform::WebGL::WEBWindow();
#endif
		}

		Window::~Window()
		{
		}

		void Window::Update()
		{
#ifdef BF_PLATFORM_WINDOWS
			winWindow->Update();
#elif BF_PLATFORM_LINUX
			lxWindow->Update();
#elif BF_PLATFORM_WEBGL
			webWindow->Update();
#endif
		}

		bool Window::IsOpen()
		{
#ifdef BF_PLATFORM_WINDOWS
			return winWindow->IsOpen();
#elif BF_PLATFORM_LINUX
			return lxWindow->IsOpen();
#elif BF_PLATFORM_WEBGL
			return webWindow->IsOpen();
#endif
		}
	}
}