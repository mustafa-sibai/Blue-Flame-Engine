#include "IndexBuffer.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			IndexBuffer::IndexBuffer()
			{
			}

			IndexBuffer::~IndexBuffer()
			{
			}

			void IndexBuffer::Create(const unsigned int* indices, unsigned int count)
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer.Create(indices, count);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Create(indices, count);
#endif	
			}

			void IndexBuffer::Bind() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer.Bind();
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Bind();
#endif	
			}

			void IndexBuffer::Unbind() const
			{
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer.Unbind();
#endif	
			}

			unsigned int IndexBuffer::GetIndicesCount() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					return dxIndexBuffer.GetIndicesCount();
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					return glIndexBuffer.GetIndicesCount();
#endif
				return 0;
			}
		}
	}
}