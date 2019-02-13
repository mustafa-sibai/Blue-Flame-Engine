#pragma once
//#include <thread>
#include "BF/Platform/API/OpenGL/GLContext.h"
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
				class BFE_API ANDGLContext
				{
					//private:
						//std::thread renderThread;
				private:
					EGLContext context;
					EGLint width;
					EGLint height;

				public:
					ANDGLContext();
					~ANDGLContext();

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