#ifdef BF_PLATFORM_LINUX
#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glxew.h>
#include "../../Application/WindowStyle.h"

namespace BF
{
	namespace Platform
	{
		namespace Linux
		{
			class BF_API LXWindow
			{
				private:
					Display *display;
					Window window;
					XEvent events;
					GLXFBConfig frameBufferConfig;

				private:
					void CheckGLXVersion();
					GLXFBConfig GetBestFrameBufferConfig(int framebuffer_attribs[]);
					void CreateWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, GLXFBConfig frameBuffer);

				public:
					LXWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style);
					~LXWindow();

					void Update();
					bool IsOpen();

					inline const Display *GetDisplay() const { return display; }
					inline const Window GetWindow() const { return window; }
					inline const GLXFBConfig GetFrameBufferConfig() const { return frameBufferConfig; }
			};
		}
	}
}
#endif