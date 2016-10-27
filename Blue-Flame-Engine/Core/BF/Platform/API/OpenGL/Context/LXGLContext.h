#pragma once
#include <stdio.h>
#include "BF/Platform/Linux/LXWindow.h"
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
				class BF_API LXGLContext
				{
					private:
						Linux::LXWindow* lxWindow;
						GLXContext context;
						const unsigned short OPENGL_CONTEXT_MAJOR_VERSION = 4;
						const unsigned short OPENGL_CONTEXT_MINOR_VERSION = 5;

					private:
						void CreateContext(bool createOldContext);
						void FinishCreatingContext(int(*oldHandler)(Display*, XErrorEvent*));

					public:
						LXGLContext(Linux::LXWindow* lxWindow);
						~LXGLContext();

						void Clear(Math::Vector4 color);
						void Draw(GLenum mode, GLsizei count, GLenum type);
						void SwapBuffers();
				};
			}
		}
	}
}