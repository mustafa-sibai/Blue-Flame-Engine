#pragma once
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glxew.h>
#include "BF/Application/WindowStyle.h"

namespace BF
{
	namespace Application { class Window; }

	namespace Platform
	{
		namespace Linux
		{
			class BF_API LXWindow
			{
				private:
					Application::Window* window;

					Display* display;
					Window xwindow;
					XEvent xEvent;
					GLXFBConfig frameBufferConfig;

				private:
					void CheckGLXVersion();
					GLXFBConfig GetBestFrameBufferConfig(int framebuffer_attribs[]);
					void CreateWindow(Application::Window* window, GLXFBConfig frameBuffer);

				public:
					LXWindow(Application::Window* window);
					~LXWindow();

					void Update();
					bool IsOpen();

					inline Display* GetDisplay() const { return display; }
					inline Window GetWindow() const { return xwindow; }
					inline GLXFBConfig GetFrameBufferConfig() const { return frameBufferConfig; }
			};
		}
	}
}