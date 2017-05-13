#pragma once
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
				class BF_API WEBGLContext : public GLContext
				{
					private:
						EGLContext context;
						EGLint width;
						EGLint height;

					public:
						WEBGLContext();
						~WEBGLContext();

						void Initialize() override;
						void SwapBuffers() override;
						void CleanUp() override;
				};
			}
		}
	}
}