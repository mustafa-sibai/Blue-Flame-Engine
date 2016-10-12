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
			inline Platform::Windows::WINWindow *GetWINWindow() const { return winWindow; }

			inline const unsigned short GetWidth() const { return winWindow->GetWidth(); }
			inline const unsigned short GetHeight() const { return winWindow->GetHeight(); }
						 
			inline const unsigned short GetClientWidth() const { return winWindow->GetClientWidth(); }
			inline const unsigned short GetClientHeight() const { return winWindow->GetClientHeight(); }

			inline float const GetAspectRatio() const { return winWindow->GetAspectRatio(); }
#elif BF_PLATFORM_LINUX
			inline Platform::Linux::LXWindow *GetLXWindow() const { return lxWindow; }
#elif BF_PLATFORM_WEBGL
			inline Platform::WebGL::WEBWindow *GetWEBWindow() const { return webWindow; }
#endif

		};
	}
}