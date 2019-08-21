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
				class BFE_API WINGLContext : public GLContext
				{
				private:
					HDC hDC;
					HGLRC context;

				public:
					WINGLContext();
					~WINGLContext();

					void Initialize() override;
					void SwapBuffers() override;
					void CleanUp() override;

					void EnableVsync(bool state) override;
				};
			}
		}
	}
}