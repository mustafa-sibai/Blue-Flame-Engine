#pragma once
//#include <thread>
#include <EGL/egl.h>
#include <GLES3/gl3.h>
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API ANDContext
				{
					//private:
						//std::thread renderThread;
				private:
					EGLContext context;
					EGLint width;
					EGLint height;

				public:
					ANDContext();
					~ANDContext();

					void Initialize();
					void Clear(const Graphics::Color& color);
					void Render();
					void SwapBuffers();
					void CleanUp();

				private:
					void RenderLoop();
				};
			}
		}
	}
}