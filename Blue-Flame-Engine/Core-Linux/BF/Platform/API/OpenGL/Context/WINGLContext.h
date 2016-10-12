#ifdef BF_PLATFORM_WINDOWS
#pragma once
#include <GL/glew.h>
#include <GL/wglew.h>
#include "../../../Windows/WINWindow.h"
#include "../../../../Math/Vector4.h"
#include "../../../../Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API WINGLContext
				{
					private:
						Windows::WINWindow *window;
						HDC hDC;
						HGLRC context;
						unsigned short const OPENGL_CONTEXT_MAJOR_VERSION = 4;
						unsigned short const OPENGL_CONTEXT_MINOR_VERSION = 5;

					public:
						WINGLContext(Windows::WINWindow *window);
						~WINGLContext();

						void Clear(Math::Vector4 color);
						void Draw(GLenum mode, GLsizei count, GLenum type);
						void SwapBuffers();
						void CleanUp();
				};
			}
		}
	}
}
#endif