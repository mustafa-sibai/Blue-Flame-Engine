#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINWindow.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/Linux/LXWindow.h"
#elif BF_PLATFORM_WEBGL
	#include "BF/Platform/WebGL/WEBWindow.h"
#endif

#include "WindowStyle.h"

namespace BF
{
	namespace Application
	{
		class BF_API Window
		{
#ifdef BF_PLATFORM_WINDOWS
			friend Platform::Windows::WINWindow;
#elif BF_PLATFORM_LINUX
			friend Platform::Linux::LXWindow;
#elif BF_PLATFORM_WEBGL
			friend Platform::WebGL::WEBWindow;
#endif

			private:
#ifdef BF_PLATFORM_WINDOWS
				Platform::Windows::WINWindow* winWindow;
#elif BF_PLATFORM_LINUX
				Platform::Linux::LXWindow* lxWindow;
#elif BF_PLATFORM_WEBGL
				Platform::WebGL::WEBWindow* webWindow;
#endif
				const char* title;
				unsigned short positionX, positionY, width, height, clientWidth, clientHeight, borderWidth, borderHeight;
				Application::WindowStyle style;

			public:
				Window(const char* title, unsigned short positionX, unsigned short positionY, unsigned short width, unsigned short height, Application::WindowStyle style);
				~Window();
				void Update();
				bool IsOpen();

#ifdef BF_PLATFORM_WINDOWS
				inline Platform::Windows::WINWindow* GetWINWindow() const { return winWindow; }

				inline unsigned short GetWidth() const { return width; }
				inline unsigned short GetHeight() const { return height; }

				inline unsigned short GetClientWidth() const { return clientWidth; }
				inline unsigned short GetClientHeight() const { return clientHeight; }

				inline float GetAspectRatio() const { return (float)width / (float)height; }
#elif BF_PLATFORM_LINUX
				inline Platform::Linux::LXWindow *GetLXWindow() const { return lxWindow; }
#elif BF_PLATFORM_WEBGL
				inline Platform::WebGL::WEBWindow *GetWEBWindow() const { return webWindow; }
#endif
		};
	}
}