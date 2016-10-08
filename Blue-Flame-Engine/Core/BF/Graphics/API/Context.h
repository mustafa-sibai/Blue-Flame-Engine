#pragma once
#include "../../Application/Window.h"
#include "../../Platform/API/DirectX/DXContext.h"
#include "../../Platform/API/OpenGL/Context/WINGLContext.h"
#include "../../Platform/API/OpenGL/Context/LXGLContext.h"
#include "../../Platform/API/OpenGL/Context/WEBGLContext.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class PrimitiveType { PointList, LineList, LineStrip, TriangleList, TriangeStrip };

			enum class BF_API RenderAPI
			{
#ifdef BF_PLATFORM_WINDOWS
				None, OpenGL, DirectX
#elif defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				None, OpenGL
#endif	
			};

			class BF_API Context
			{
				private:
					Application::Window *window;
					static RenderAPI renderAPI;
					GLuint GL_PRIMITIVE_TYPE;
#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXContext *dxContext;
					Platform::API::OpenGL::WINGLContext *winGLContext;
#elif BF_PLATFORM_LINUX
					Platform::API::OpenGL::LXGLContext *lxGLContext;
#elif BF_PLATFORM_WEBGL
					Platform::API::OpenGL::WEBGLContext *webGLContext;
#endif
				public:
					Context(Application::Window *window, RenderAPI renderAPI);
					~Context();
					void SetPrimitiveType(PrimitiveType primitiveType);
					void Clear(Math::Vector4 Color);
					void Draw(const unsigned int vertexCount);
					void SwapBuffers();

#ifdef BF_PLATFORM_WINDOWS
					inline Platform::API::DirectX::DXContext *GetDXContext() const { return dxContext; }
					inline const Platform::API::OpenGL::WINGLContext *GetWINGLContext() const { return winGLContext; }
#elif BF_PLATFORM_LINUX
					inline const Platform::API::OpenGL::LXGLContext  *GetLXGLContext() const { return lxGLContext; }
#elif BF_PLATFORM_WEBGL
					inline const Platform::API::OpenGL::WEBGLContext  *GetWEBGLContext() const { return webGLContext; }
#endif
					static const inline RenderAPI GetRenderAPI() { return renderAPI; }
			};
		}
	}
}