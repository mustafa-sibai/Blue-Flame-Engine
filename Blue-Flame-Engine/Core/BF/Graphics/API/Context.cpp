#include "Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			RenderAPI Context::renderAPI = RenderAPI::None;

			Context::Context(Application::Window *window, RenderAPI renderAPI) :
				window(window), GL_PRIMITIVE_TYPE(0)
			{
				this->renderAPI = renderAPI;

#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext = new Platform::API::DirectX::DXContext(window->GetWINWindow());
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext = new Platform::API::OpenGL::WINGLContext(window->GetWINWindow());
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext = new Platform::API::OpenGL::LXGLContext(window->GetLXWindow());
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext = new Platform::API::OpenGL::WEBGLContext(window->GetWEBWindow());
#endif
			}

			Context::~Context()
			{
			}

			void Context::SetPrimitiveType(PrimitiveType primitiveType)
			{
#ifdef BF_PLATFORM_WINDOWS
				D3D_PRIMITIVE_TOPOLOGY D3DPrimitiveType = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
#endif
				switch (primitiveType)
				{
				case PrimitiveType::PointList:
				{
#ifdef BF_PLATFORM_WINDOWS
					if (renderAPI == RenderAPI::DirectX)		D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					if (renderAPI == RenderAPI::OpenGL)			GL_PRIMITIVE_TYPE = GL_POINTS;
#endif
					break;
				}
				case PrimitiveType::LineList:
				{
#ifdef BF_PLATFORM_WINDOWS
					if (renderAPI == RenderAPI::DirectX)		D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINELIST;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					if (renderAPI == RenderAPI::OpenGL)			GL_PRIMITIVE_TYPE = GL_LINES;
#endif
					break;
				}
				case PrimitiveType::LineStrip:
				{
#ifdef BF_PLATFORM_WINDOWS
					if (renderAPI == RenderAPI::DirectX)		D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					if (renderAPI == RenderAPI::OpenGL)			GL_PRIMITIVE_TYPE = GL_LINE_STRIP;
#endif
					break;
				}
				case PrimitiveType::TriangleList:
				{
#ifdef BF_PLATFORM_WINDOWS
					if (renderAPI == RenderAPI::DirectX)		D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					if (renderAPI == RenderAPI::OpenGL)			GL_PRIMITIVE_TYPE = GL_TRIANGLES;
#endif
					break;
				}
				case PrimitiveType::TriangeStrip:
				{
#ifdef BF_PLATFORM_WINDOWS
					if (renderAPI == RenderAPI::DirectX)		D3DPrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
					if (renderAPI == RenderAPI::OpenGL)			GL_PRIMITIVE_TYPE = GL_TRIANGLE_STRIP;
#endif
					break;
				}
				default:
					break;
				}

#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->GetContext()->IASetPrimitiveTopology(D3DPrimitiveType);
#endif
			}

			void Context::Clear(Math::Vector4 color)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->Clear(color);
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext->Clear(color);
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->Clear(color);
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->Clear(color);
#endif
			}

			void Context::Draw(const unsigned int vertexCount)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->GetContext()->Draw(vertexCount, 0);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					glDrawArrays(GL_TRIANGLES, 0, vertexCount);
#endif
			}

			void Context::SwapBuffers()
			{
#ifdef BF_PLATFORM_WINDOWS
				if (renderAPI == RenderAPI::DirectX)
					dxContext->SwapBuffers();
				else if (renderAPI == RenderAPI::OpenGL)
					winGLContext->SwapBuffers();
#elif BF_PLATFORM_LINUX
				if (renderAPI == RenderAPI::OpenGL)
					lxGLContext->SwapBuffers();
#elif BF_PLATFORM_WEBGL
				if (renderAPI == RenderAPI::OpenGL)
					webGLContext->SwapBuffers();
#endif
			}
		}
	}
}