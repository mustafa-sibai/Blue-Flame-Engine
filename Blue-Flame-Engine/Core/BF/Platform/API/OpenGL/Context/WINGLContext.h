#pragma once
#include <GL/glew.h>
#include <GL/wglew.h>
#include "BF/Application/Window.h"
#include "BF/Math/Vector4.h"
#include "BF/Common.h"

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
						Application::Window* window;
						HDC hDC;
						HGLRC context;
						const unsigned short OPENGL_CONTEXT_MAJOR_VERSION = 4;
						const unsigned short OPENGL_CONTEXT_MINOR_VERSION = 5;

					public:
						WINGLContext(Application::Window* window);
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