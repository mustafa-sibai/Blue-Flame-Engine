#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/API/DirectX/DXContext.h"
	#include "BF/Platform/API/OpenGL/Context/WINGLContext.h"
#elif defined(BFE_PLATFORM_LINUX)
	#include "BF/Platform/API/OpenGL/Context/LXGLContext.h"
#elif defined(BFE_PLATFORM_WEB)
	#include "BF/Platform/API/OpenGL/Context/WEBGLContext.h"
#elif defined(BFE_PLATFORM_ANDROID)
	#include "BF/Platform/API/OpenGL/Context/ANDGLContext.h"
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
			enum class PrimitiveType { None, PointList, LineList, LineStrip, TriangleList, TriangeStrip };
			enum class BufferClearType { None, Color, Depth, ColorAndDepth };
			enum class WindingOrder { None, Clockwise, CounterClockwise };
			enum class CullingType { None, Front, Back, FrontAndBack };

			enum class BFE_API RenderAPI
			{
#ifdef BFE_PLATFORM_WINDOWS
				OpenGL, DirectX
#elif defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				OpenGL
#endif	
			};

			class BFE_API Context
			{
				private:
					static RenderAPI renderAPI;

#ifdef BFE_PLATFORM_WINDOWS
					Platform::API::DirectX::DXContext dxContext;
					Platform::API::OpenGL::WINGLContext winGLContext;
#elif defined(BFE_PLATFORM_LINUX)
					Platform::API::OpenGL::LXGLContext lxGLContext;
#elif defined(BFE_PLATFORM_WEB)
					Platform::API::OpenGL::WEBGLContext webGLContext;
#elif defined(BFE_PLATFORM_ANDROID)
					Platform::API::OpenGL::ANDGLContext andGLContext;
#endif
				public:
					Context(RenderAPI renderAPI);
					~Context();

					void Initialize();
					void SetPrimitiveType(PrimitiveType primitiveType);
					void Clear(BufferClearType bufferClearType, const Color& color);
					void Draw(unsigned int vertexCount);
					void SwapBuffers();
					
					void EnableDepthBuffer(bool state);
					void EnableDepthMask(bool state);
					void EnableBlending(bool state);
					void EnableVsync(bool state);
					void EnableScissor(bool state);

					void SetScissor(const Math::Rectangle& rectangle);
					void SetViewport(const Math::Rectangle& rectangle);

					void SetWindingOrder(WindingOrder windingOrder);
					void CullFace(CullingType cullingType);

#ifdef BFE_PLATFORM_WINDOWS
					inline const Platform::API::DirectX::DXContext& GetDXContext() const { return dxContext; }
					inline const Platform::API::OpenGL::WINGLContext& GetWINGLContext() const { return winGLContext; }
#elif defined(BFE_PLATFORM_LINUX)
					inline const Platform::API::OpenGL::LXGLContext& GetLXGLContext() const { return lxGLContext; }
#elif defined(BFE_PLATFORM_WEB)
					inline const Platform::API::OpenGL::WEBGLContext& GetWEBGLContext() const { return webGLContext; }
#elif defined(BFE_PLATFORM_ANDROID)
					inline Platform::API::OpenGL::ANDGLContext& GetAContext() { return ANDGLContext; }
#endif
					static const inline RenderAPI GetRenderAPI() { return renderAPI; }
			};
		}
	}
}