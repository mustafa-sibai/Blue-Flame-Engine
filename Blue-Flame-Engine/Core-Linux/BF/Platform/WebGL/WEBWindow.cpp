#ifdef BF_PLATFORM_WEBGL
#include "WEBWindow.h"

namespace BF
{
	namespace Platform
	{
		namespace WebGL
		{
			WEBWindow::WEBWindow() : 
				display(0), numConfigs(0)
			{
				display = eglGetDisplay(EGL_DEFAULT_DISPLAY);
				if (display != EGL_NO_DISPLAY)
				{
					//print error
				}

				EGLint major, minor;
				EGLBoolean ret = eglInitialize(display, &major, &minor);
				if (ret != EGL_TRUE)
				{
					//print error
				}

				ret = eglGetConfigs(display, 0, 0, &numConfigs);
				if (ret != EGL_TRUE)
				{
					//print error
				}
			}

			WEBWindow::~WEBWindow()
			{
			}

			void WEBWindow::Update()
			{
			}

			bool WEBWindow::IsOpen()
			{
				return true;
			}
		}
	}
}
#endif