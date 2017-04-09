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
#ifdef BF_PLATFORM_WINDOWS
					renderAPI = RenderAPI::DirectX;
#elif defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
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
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Initialize();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Initialize();
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Initialize();
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					andContext.Initialize();
#endif
			}

			void Context::SetPrimitiveType(PrimitiveType primitiveType)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.SetPrimitiveType(primitiveType);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetPrimitiveType(primitiveType);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SetPrimitiveType(primitiveType);
#elif BF_PLATFORM_ANDROID
				//if (renderAPI == RenderAPI::OpenGL)
					//aContext.SetPrimitiveType();
#endif
			}

			void Context::Clear(const Color& color)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Clear(color);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Clear(color);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Clear(color);
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Clear(color);
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					andContext.Clear(color);
#endif
			}

			void Context::Draw(unsigned int vertexCount)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Render(vertexCount);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Render(vertexCount);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Render(GL_PRIMITIVE_TYPE, vertexCount, GL_UNSIGNED_INT);
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Render(vertexCount);
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					andContext.Render();
#endif
			}

			void Context::SwapBuffers()
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.SwapBuffers();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SwapBuffers();
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.SwapBuffers();
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SwapBuffers();
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					andContext.SwapBuffers();
#endif
			}

			void Context::EnableDepthBuffer(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthBuffer(state);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{

				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::EnableDepthMask(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthMask(state);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::EnableBlending(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableBlending(state);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::EnableVsync(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableVsync(state);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{

				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::EnableScissor(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableScissor(state);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{

				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::SetScissor(const Math::Rectangle& rectangle)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetScissor(rectangle);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}

			void Context::SetViewport(const Math::Rectangle & rectangle)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
				{
				}
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetViewport(rectangle);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_WEB
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
				{
				}
#endif
			}
		}
	}
}