#pragma once
#include "../Platform/Windows/WINWindow.h"
#include "../Platform/Linux/LXWindow.h"
#include "../Platform/WebGL/WEBWindow.h"
#include "WindowStyle.h"

namespace BF
{
	namespace Application
	{
		class BF_API Window
		{
		private:
#ifdef BF_PLATFORM_WINDOWS
			Platform::Windows::WINWindow *winWindow;
#elif BF_PLATFORM_LINUX
			Platform::Linux::LXWindow *lxWindow;
#elif BF_PLATFORM_WEBGL
			Platform::WebGL::WEBWindow *webWindow;
#endif
		public:
			Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style);
			~Window();
			void Update();
			bool IsOpen();

#ifdef BF_PLATFORM_WINDOWS
			inline Platform::Windows::WINWindow *GetWINWindow() { return winWindow; }

			inline unsigned short const GetWidth() const { return winWindow->GetWidth(); }
			inline unsigned short const GetHeight() const { return winWindow->GetHeight(); }

			inline unsigned short const GetClientWidth() const { return winWindow->GetClientWidth(); }
			inline unsigned short const GetClientHeight() const { return winWindow->GetClientHeight(); }

			inline float const GetAspectRatio() const { return winWindow->GetAspectRatio(); }
#elif BF_PLATFORM_LINUX
			inline Platform::Linux::LXWindow *GetLXWindow() { return lxWindow; }
#elif BF_PLATFORM_WEBGL
			inline Platform::WebGL::WEBWindow *GetWEBWindow() { return webWindow; }
#endif

		};
	}
}