#pragma once
#include <stdio.h>
#include "BF/Platform/API/OpenGL/GLContext.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API LXGLContext : public GLContext
				{
					private:
						GLXContext context;
						const unsigned short OPENGL_CONTEXT_MAJOR_VERSION = 4;
						const unsigned short OPENGL_CONTEXT_MINOR_VERSION = 5;

					public:
						LXGLContext();
						~LXGLContext();

						void Initialize() override;
						void SwapBuffers() override;
						void CleanUp() override;

					private:
						void CreateContext(bool createOldContext);
						void FinishCreatingContext(int(*oldHandler)(Display*, XErrorEvent*));
				};
			}
		}
	}
}