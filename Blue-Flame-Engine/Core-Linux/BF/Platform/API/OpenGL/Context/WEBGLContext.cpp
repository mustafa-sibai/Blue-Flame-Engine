#ifdef BF_PLATFORM_WEBGL
#include "WEBGLContext.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				WEBGLContext::WEBGLContext(WebGL::WEBWindow *webWindow) :
					webWindow(webWindow)
				{
					EGLint attribs[] = {
						EGL_RED_SIZE, 5,
						EGL_GREEN_SIZE, 6,
						EGL_BLUE_SIZE, 5,
						EGL_NONE
					};

					EGLint contextAttribs[] =
					{
						EGL_CONTEXT_CLIENT_VERSION, 2,
						EGL_NONE
					};

					EGLBoolean ret = eglChooseConfig(webWindow->GetDisplay(), attribs, &config, 1, webWindow->GetNumConfigs());
					if (ret != EGL_TRUE)
					{
						//print error
					}

					EGLSurface surface = eglCreateWindowSurface(webWindow->GetDisplay(), config, window, 0);
					if (surface != 0)
					{
						//print error
					}

					EGLContext context = eglCreateContext(webWindow->GetDisplay(), config, 0, contextAttribs);
					if (context != 0)
					{
						//print error
					}

					ret = eglMakeCurrent(webWindow->GetDisplay(), surface, surface, context);
					if (ret != EGL_TRUE)
					{

					}
				}

				WEBGLContext::~WEBGLContext()
				{
				}

				void WEBGLContext::Clear(Math::Vector4 color)
				{
					glClearColor(color.x, color.y, color.z, color.w);
					glClear(GL_COLOR_BUFFER_BIT);
				}

				void WEBGLContext::SwapBuffers()
				{
					eglSwapInterval(webWindow->GetDisplay(), 0);
				}
			}
		}
	}
}
#endif