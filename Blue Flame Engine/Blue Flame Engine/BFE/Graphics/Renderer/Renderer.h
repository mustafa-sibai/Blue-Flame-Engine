#pragma once
#include "PlatformSpecific/DX11Renderer.h"
#include "PlatformSpecific/GLRenderer.h"
#include "../../Math/Math.h"

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
		class DLLEXPORT Renderer
		{
			public:
				enum RenderingAPI
				{
					DirectX11,
					OpenGL4_5
				};

				enum PrimitiveType
				{
					PointList, LineList, LineStrip, TriangleList, TriangeStrip
				};

				static RenderingAPI renderingAPI;

			private:
				Window &window;
				DX11Renderer dx11Renderer;
				GLRenderer glRenderer;
				GLuint GL_PRIMITIVE_TYPE;

			public:
				Renderer(Window &window);
				~Renderer();

				void Initialize();
				void SetPrimitiveType(PrimitiveType primitiveType);
				void Clear(Math::Vector4 Color);
				void Draw(const unsigned int vertexCount);
				void SwapBuffers();
				void CleanUp();

				inline DX11Renderer &GetDx11Renderer()  { return dx11Renderer; }
				inline GLRenderer &GetGLRenderer() { return glRenderer; }
		};
	}
}