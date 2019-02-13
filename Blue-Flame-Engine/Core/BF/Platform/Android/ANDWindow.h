#pragma once
#define INCLUDE_OPENGL
#include <android/native_window.h>
#include "BF/Platform/API/OpenGL/Context/ANDGLContext.h"
#include "BF/Application/Window.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace Android
		{
			class BFE_API ANDWindow : public Application::Window
			{
				friend class BF::Platform::API::OpenGL::ANDGLContext;

				private:
					ANativeWindow* window;

					EGLint eglMajVers, eglMinVers;

					EGLDisplay display;
					EGLSurface surface;
					EGLConfig config;
					EGLint numConfigs;
					EGLint format;

				public:
					ANDWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style);
					~ANDWindow();

					void Initialize(ANativeWindow* window);
					void Update();
					bool IsOpen();
			};
		}
	}
}