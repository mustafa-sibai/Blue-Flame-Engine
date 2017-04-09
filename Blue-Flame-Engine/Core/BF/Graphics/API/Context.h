#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXContext.h"
	#include "BF/Platform/API/OpenGL/Context/WINGLContext.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/API/OpenGL/Context/LXGLContext.h"
#elif BF_PLATFORM_WEB
	#include "BF/Platform/API/OpenGL/Context/WEBGLContext.h"
#elif BF_PLATFORM_ANDROID
	#include "BF/Platform/API/OpenGL/Context/ANDContext.h"
#endif

#include "BF/Math/Rectangle.h"
#include "BF/Graphics/Color.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			enum class PrimitiveType { PointList, LineList, LineStrip, TriangleList, TriangeStrip };

			enum class BF_API RenderAPI
			{
				Default,
#ifdef BF_PLATFORM_WINDOWS
				DirectX, OpenGL
#elif defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
				OpenGL
#endif	
			};

			class BF_API Context
			{
				private:
					static RenderAPI renderAPI;

#ifdef BF_PLATFORM_WINDOWS
					Platform::API::DirectX::DXContext dxContext;
					Platform::API::OpenGL::WINGLContext winGLContext;
#elif BF_PLATFORM_LINUX
					Platform::API::OpenGL::LXGLContext lxGLContext;
#elif BF_PLATFORM_WEB
					Platform::API::OpenGL::WEBGLContext webGLContext;
#elif BF_PLATFORM_ANDROID
					Platform::API::OpenGL::ANDContext andContext;
#endif
				public:
					Context(RenderAPI renderAPI);
					~Context();

					void Initialize();
					void SetPrimitiveType(PrimitiveType primitiveType);
					void Clear(const Color& color);
					void Draw(unsigned int vertexCount);
					void SwapBuffers();
					
					void EnableDepthBuffer(bool state);
					void EnableDepthMask(bool state);
					void EnableBlending(bool state);
					void EnableVsync(bool state);
					void EnableScissor(bool state);

					void SetScissor(const Math::Rectangle& rectangle);
					void SetViewport(const Math::Rectangle& rectangle);

#ifdef BF_PLATFORM_WINDOWS
					inline const Platform::API::DirectX::DXContext& GetDXContext() const { return dxContext; }
					inline const Platform::API::OpenGL::WINGLContext& GetWINGLContext() const { return winGLContext; }
#elif BF_PLATFORM_LINUX
					inline const Platform::API::OpenGL::LXGLContext& GetLXGLContext() const { return lxGLContext; }
#elif BF_PLATFORM_WEB
					inline const Platform::API::OpenGL::WEBGLContext& GetWEBGLContext() const { return webGLContext; }
#elif BF_PLATFORM_ANDROID
					inline Platform::API::OpenGL::ANDContext& GetAContext() { return andContext; }
#endif
					static const inline RenderAPI GetRenderAPI() { return renderAPI; }
			};
		}
	}
}