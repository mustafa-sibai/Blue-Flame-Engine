#pragma once
#include <iostream>
#include <GLEW/GL/glew.h>
#include <GLEW/GL/wglew.h>
#include "../../../Math/Vector4.h"


#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Graphics
	{
		class Window;
		class DLLEXPORT GLRenderer
		{
		private:
			HDC windowHandleToDeviceContext;

			public:
				Window &window;

				GLRenderer(Window &window);
				~GLRenderer();

				void Initialize();
				void Clear(Math::Vector4 Color);
				void SwapBuffers();
				void CleanUp();
		};
	}
}