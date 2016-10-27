#pragma once
#include <GLES3/gl3.h>
#include "BF/Math/Vector4.h"
#include "BF/Platform/WebGL/WEBWindow.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class WEBGLContext
				{
					private:
						WebGL::WEBWindow* webWindow;
						EGLConfig config;
						EGLNativeWindowType window;

					public:
						WEBGLContext(WebGL::WEBWindow* webWindow);
						~WEBGLContext();

						void Clear(Math::Vector4 Color);
						void SwapBuffers();
				};
			}
		}
	}
}