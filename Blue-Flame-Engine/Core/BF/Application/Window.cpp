#include "Window.h"

namespace BF
{
	namespace Application
	{
		Window::Window(const std::string& title, unsigned short positionX, unsigned short positionY, unsigned short width, unsigned short height, Application::WindowStyle style) :
			title(title), positionX(positionX), positionY(positionY), width(width), height(height), style(style), clientWidth(0), clientHeight(0), borderWidth(0), borderHeight(0),
#ifdef BF_PLATFORM_WINDOWS
			winWindow(this)
#elif BF_PLATFORM_LINUX
			lxWindow(this)
#endif
		{
		}

		Window::~Window()
		{
		}

		void Window::Update()
		{
#ifdef BF_PLATFORM_WINDOWS
			winWindow.Update();
#elif BF_PLATFORM_LINUX
			lxWindow.Update();
#elif BF_PLATFORM_WEBGL
			webWindow.Update();
#endif
		}

		bool Window::IsOpen()
		{
#ifdef BF_PLATFORM_WINDOWS
			return winWindow.IsOpen();
#elif BF_PLATFORM_LINUX
			return lxWindow.IsOpen();
#elif BF_PLATFORM_WEBGL
			return webWindow.IsOpen();
#endif
		}
	}
}