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
#elif defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
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
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Initialize();
#endif
			}

			void Context::SetPrimitiveType(PrimitiveType primitiveType)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.SetPrimitiveType(primitiveType);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.SetPrimitiveType(primitiveType);
#endif
			}

			void Context::Clear(Math::Vector4 color)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Clear(color);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Clear(color);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->Clear(color);
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->Clear(color);
#endif
			}

			void Context::Draw(unsigned int vertexCount)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.Draw(vertexCount);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext.Draw(vertexCount);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext.Draw(GL_PRIMITIVE_TYPE, vertexCount, GL_UNSIGNED_INT);
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Draw(GL_PRIMITIVE_TYPE, vertexCount, GL_UNSIGNED_INT);
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
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.SwapBuffers();
#endif
			}

			void Context::EnableDepthBuffer(bool state)
			{

#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.EnableDepthBuffer(state);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthBuffer(state);
#endif
			}
		}
	}
}