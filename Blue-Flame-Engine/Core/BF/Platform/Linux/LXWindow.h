#pragma once
#include <stdio.h>
#include <string>
#include "DependencyHeaders/GLEW/GL/glew.h"
#include "DependencyHeaders/GLEW/GL/glxew.h"
#include "BF/Application/Window.h"
#include "BF/Common.h"

namespace BF
{
	typedef Window XWindow;

	namespace Application { class Window; }

	namespace Platform
	{
		namespace Linux
		{
			class BFE_API LXWindow : public Application::Window
			{
				private:
					Display* display;
					XWindow xwindow;
					XEvent xEvent;
					GLXFBConfig frameBufferConfig;

				private:
					void CheckGLXVersion();
					GLXFBConfig GetBestFrameBufferConfig(int framebuffer_attribs[]);
					void CreateWindow(GLXFBConfig frameBuffer);

				public:
					LXWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style);
					~LXWindow();

					void Initialize();
					void Update();
					bool IsOpen();

					inline Display* GetDisplay() const { return display; }
					inline XWindow GetXWindow() const { return xwindow; }
					inline GLXFBConfig GetFrameBufferConfig() const { return frameBufferConfig; }
			};
		}
	}
}