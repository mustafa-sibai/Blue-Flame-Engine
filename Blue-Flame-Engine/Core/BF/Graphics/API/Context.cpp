#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			RenderAPI Context::renderAPI = RenderAPI::Default;

			Context::Context(RenderAPI renderAPI)
			{
				if (renderAPI == RenderAPI::Default)
				{
#ifdef BFE_PLATFORM_WINDOWS
					renderAPI = RenderAPI::DirectX;
#elif defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
					renderAPI = RenderAPI::OpenGL;
#endif
				}

				this->renderAPI = renderAPI;
			}

			Context::~Context()
			{
			}

			void Context::Initialize()
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Initialize();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Initialize();
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Initialize();
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Initialize();
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.Initialize();
#endif
			}

			void Context::SetPrimitiveType(PrimitiveType primitiveType)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.SetPrimitiveType(primitiveType);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetPrimitiveType(primitiveType);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.SetPrimitiveType(primitiveType);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SetPrimitiveType(primitiveType);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.SetPrimitiveType(primitiveType);
#endif
			}

			void Context::Clear(BufferClearType bufferClearType, const Color& color)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Clear(color);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Clear(bufferClearType, color);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Clear(color);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Clear(color);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.Clear(color);
#endif
			}

			void Context::Draw(unsigned int vertexCount)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Render(vertexCount);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Render(vertexCount);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Render(vertexCount);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Render(vertexCount);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.Render();
#endif
			}

			void Context::SwapBuffers()
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.SwapBuffers();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SwapBuffers();
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.SwapBuffers();
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SwapBuffers();
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.SwapBuffers();
#endif
			}

			void Context::EnableDepthBuffer(bool state)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthBuffer(state);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.EnableDepthBuffer(state);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.EnableDepthBuffer(state);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.EnableDepthBuffer(state);
#endif
			}

			void Context::EnableDepthMask(bool state)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthMask(state);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.EnableDepthMask(state);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.EnableDepthMask(state);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.EnableDepthMask(state);
#endif
			}

			void Context::EnableBlending(bool state)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableBlending(state);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.EnableBlending(state);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.EnableBlending(state);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.EnableBlending(state);
#endif
			}

			void Context::EnableVsync(bool state)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableVsync(state);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.EnableVsync(state);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.EnableVsync(state);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.EnableVsync(state);
#endif
			}

			void Context::EnableScissor(bool state)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableScissor(state);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.EnableScissor(state);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.EnableScissor(state);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.EnableScissor(state);
#endif
			}

			void Context::SetScissor(const Math::Rectangle& rectangle)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetScissor(rectangle);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.SetScissor(rectangle);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SetScissor(rectangle);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.SetScissor(rectangle);
#endif
			}

			void Context::SetViewport(const Math::Rectangle & rectangle)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetViewport(rectangle);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.SetViewport(rectangle);
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SetViewport(rectangle);
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
					andGLContext.SetViewport(rectangle);
#endif
			}

			void Context::SetWindingOrder(WindingOrder windingOrder)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetWindingOrder(windingOrder);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::CullFace(CullingType cullingType)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.CullFace(cullingType);
#elif defined(BFE_PLATFORM_LINUX)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif defined(BFE_PLATFORM_WEB)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif defined(BFE_PLATFORM_ANDROID)
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}
		}
	}
}