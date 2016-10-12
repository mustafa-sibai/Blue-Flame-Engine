#include "IndexBuffer.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			IndexBuffer::IndexBuffer(Context *context) :
				context(context)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer = new Platform::API::DirectX::DXIndexBuffer(context->GetDXContext());
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer = new Platform::API::OpenGL::GLIndexBuffer();
#endif	
			}

			IndexBuffer::~IndexBuffer()
			{
			}

			void IndexBuffer::Create(const unsigned int* const indices, const unsigned int count)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer->Create(indices, count);
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer->Create(indices, count);
#endif	
			}

			const void IndexBuffer::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer->Bind();
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer->Bind();
#endif	
			}

			const void IndexBuffer::Unbind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxIndexBuffer->Unbind();
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glIndexBuffer->Unbind();
#endif	
			}


			const unsigned int IndexBuffer::GetIndicesCount() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					return dxIndexBuffer->GetIndicesCount();
#endif
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX || defined BF_PLATFORM_WEBGL
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					return glIndexBuffer->GetIndicesCount();
#endif
			}
		}
	}
}