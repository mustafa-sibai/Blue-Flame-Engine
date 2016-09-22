#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include <iostream>
//#include"../../../Util/Log.h"
#include <GL/glew.h>
#include <GL/wglew.h>
#include "../Windows/WINWindow.h"
#include "../../Math/Vector4.h"
#include "../../Common.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			class BF_API WINGLContext
			{
				private:
					WINWindow *window;
					HDC hDC;
					HGLRC context;
					unsigned short const OPENGL_CONTEXT_MAJOR_VERSION = 4;
					unsigned short const OPENGL_CONTEXT_MINOR_VERSION = 5;

				public:
					WINGLContext(WINWindow *window);
					~WINGLContext();

					void Clear(Math::Vector4 Color);
					void SwapBuffers();
					void CleanUp();
			};
		}
	}
}
#endif