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
#elif defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL) || defined (BF_PLATFORM_ANDROID)
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
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					aContext.Initialize();
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
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext.Clear(color);
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					aContext.Clear(color);
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
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					aContext.Draw();
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
#elif BF_PLATFORM_ANDROID
				if (renderAPI == RenderAPI::OpenGL)
					aContext.SwapBuffers();
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

			void Context::EnableDepthMask(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				//if (renderAPI == RenderAPI::DirectX)
					//dxContext.EnableDepthBuffer(state);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableDepthMask(state);
#endif
			}

			void Context::EnableBlending(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.EnableBlending(state);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableBlending(state);
#endif
			}

			void Context::EnableVsync(bool state)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext.EnableVsync(state);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (renderAPI == RenderAPI::OpenGL)
					winGLContext.EnableVsync(state);
#endif
			}
		}
	}
}