#ifdef BF_PLATFORM_LINUX
#pragma once
#include <stdio.h>
#include "../Linux/LXWindow.h"
#include "../../Common.h"
#include "../../Math/Vector4.h"

namespace BF
{
	namespace Platform
	{
		namespace Linux
		{
			class BF_API LXGLContext
			{
				private:
					LXWindow *lxWindow;
					GLXContext context;
					unsigned short const OPENGL_CONTEXT_MAJOR_VERSION = 4;
					unsigned short const OPENGL_CONTEXT_MINOR_VERSION = 5;

				private:
					void CreateContext(bool createOldContext);
					void FinishCreatingContext(int(*oldHandler)(Display*, XErrorEvent*));

				public:
					LXGLContext(LXWindow *lxWindow);
					~LXGLContext();

					void Clear(Math::Vector4 Color);
					void SwapBuffers();
			};
		}
	}
}
#endif