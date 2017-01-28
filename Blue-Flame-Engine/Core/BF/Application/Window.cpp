#include "Window.h"

namespace BF
{
	namespace Application
	{
		Window::Window(const std::string& title, unsigned short positionX, unsigned short positionY, unsigned short width, unsigned short height, Application::WindowStyle style) :
			WINWindow(title, positionX, positionY, width, height, style)
		{
		}

		Window::~Window()
		{
		}

		void Window::Initialize()
		{
#ifdef BF_PLATFORM_WINDOWS
			WINWindow::Initialize();
#elif BF_PLATFORM_LINUX
			LXWindow::Initialize();
#elif BF_PLATFORM_WEBGL
			WEBWindow::Initialize();
#elif BF_PLATFORM_ANDROID
			AWindow::Initialize();
#endif
		}

		void Window::Update()
		{
#ifdef BF_PLATFORM_WINDOWS
			WINWindow::Update();
#elif BF_PLATFORM_LINUX
			LXWindow::Update();
#elif BF_PLATFORM_WEBGL
			WEBWindow::Update();
#elif BF_PLATFORM_ANDROID
			AWindow::Update();
#endif
		}

		bool Window::IsOpen()
		{
#ifdef BF_PLATFORM_WINDOWS
			return WINWindow::IsOpen();
#elif BF_PLATFORM_LINUX
			return LXWindow::IsOpen();
#elif BF_PLATFORM_WEBGL
			return WEBWindow::IsOpen();
#elif BF_PLATFORM_ANDROID
			return AWindow::IsOpen();
#endif
		}
	}
}