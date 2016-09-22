#include "Window.h"

namespace BF
{
	namespace Application
	{
		Window::Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style, Graphics::RenderAPI renderAPI)
		{

#ifdef BF_PLATFORM_WINDOWS
			winWindow = new Platform::Windows::WINWindow(title, x, y, width, height, style, renderAPI);
			winGLContext = new Platform::Windows::WINGLContext(winWindow);
#elif BF_PLATFORM_LINUX
			lxWindow = new Platform::Linux::LXWindow(title, x, y, width, height, style, renderAPI);
			lxGLContext = new Platform::Linux::LXGLContext(lxWindow);
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
#endif
		}

		bool Window::IsOpen()
		{
#ifdef BF_PLATFORM_WINDOWS
			return winWindow->IsOpen();
#elif BF_PLATFORM_LINUX
			return lxWindow->IsOpen();
#endif
		}

		void Window::Clear(Math::Vector4 Color)
		{
#ifdef BF_PLATFORM_WINDOWS
			winGLContext->Clear(Color);
#elif BF_PLATFORM_LINUX
			lxGLContext->Clear(Color);
#endif
		}

		void Window::SwapBuffers()
		{
#ifdef BF_PLATFORM_WINDOWS
			winGLContext->SwapBuffers();
#elif BF_PLATFORM_LINUX
			lxGLContext->SwapBuffers();
#endif
		}
	}
}