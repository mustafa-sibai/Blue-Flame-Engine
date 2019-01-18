#include "VertexBuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			VertexBuffer::VertexBuffer()
			{
			}

			VertexBuffer::~VertexBuffer()
			{
			}

			void VertexBuffer::Create(unsigned int size, void* data)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxVertexBuffer.Create(data, size);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexBuffer.Create(size, data);
#endif
			}

			void VertexBuffer::SetLayout(const Shader& shader, const VertexBufferLayout* vertexBufferLayout)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
				{
					//dxVertexBuffer.SetLayout(shader.dxShader, vertexBufferLayout);
				}
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexBuffer.SetLayout(vertexBufferLayout);
#endif
			}

			void* VertexBuffer::Map() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					return dxVertexBuffer.Map();
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					return glVertexBuffer.Map();
#endif
				return nullptr;
			}

			void VertexBuffer::Unmap() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxVertexBuffer.Unmap();
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexBuffer.Unmap();
#endif
			}

			void VertexBuffer::Bind() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxVertexBuffer.Bind();
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexBuffer.Bind();
#endif
			}

			void VertexBuffer::Unbind() const
			{
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexBuffer.Unbind();
#endif
			}
		}
	}
}