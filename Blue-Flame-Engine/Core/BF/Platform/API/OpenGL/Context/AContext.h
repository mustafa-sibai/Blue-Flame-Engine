#pragma once
//#include <thread>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
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
				class BF_API AContext
				{
					//private:
						//std::thread renderThread;
				private:
					EGLDisplay display;
					EGLConfig config;
					EGLint numConfigs;
					EGLint format;
					EGLSurface surface;
					EGLContext context;
					EGLint width;
					EGLint height;
					GLfloat ratio;

				public:
					AContext();
					~AContext();

					void Initialize();
					void Clear();
					void Draw();
					void SwapBuffers();
					void CleanUp();

				private:
					void RenderLoop();
				};
			}
		}
	}
}