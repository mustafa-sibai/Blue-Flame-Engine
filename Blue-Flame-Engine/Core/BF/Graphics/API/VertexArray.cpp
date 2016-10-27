#include "VertexArray.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			VertexArray::VertexArray(Context* context, Shader* shader) :
				context(context)
			{
#ifdef BF_PLATFORM_WINDOWS
				//if (Context::GetRenderAPI() == RenderAPI::DirectX)
				//	dxVertexArray = new Platform::API::DirectX::DXVertexBuffer(context->GetDXContext(), shader->GetDXShader());
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray = new Platform::API::OpenGL::GLVertexArray();
#endif
			}

			VertexArray::~VertexArray()
			{
			}

			void VertexArray::Create()
			{
#ifdef BF_PLATFORM_WINDOWS
				//if (Context::GetRenderAPI() == RenderAPI::DirectX)
					//dxVertexArray->Create(data, size);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray->Create();
#endif
			}

			void VertexArray::Push(VertexBuffer* vertexBuffer)
			{
#ifdef BF_PLATFORM_WINDOWS
				//	if (Context::GetRenderAPI() == RenderAPI::DirectX)
				//	dxVertexArray->Push(vertexBuffer->GetDxVertexBuffer());
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray->Push(vertexBuffer->GetGLVertexBuffer());
#endif
			}

			void VertexArray::SetVertexBufferLayout(Graphics::API::VertexBufferLayout* vertexBufferLayout)
			{
#ifdef BF_PLATFORM_WINDOWS
				//	if (Context::GetRenderAPI() == RenderAPI::DirectX)
				//	dxVertexArray->SetLayout(vertexBufferLayout);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray->SetVertexBufferLayout(vertexBufferLayout);
#endif
			}

			void VertexArray::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				//if (Context::GetRenderAPI() == RenderAPI::DirectX)
					//dxVertexArray->Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray->Bind();
#endif
			}

			void VertexArray::Unbind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				//if (Context::GetRenderAPI() == RenderAPI::DirectX)
					//dxVertexArray->Unbind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glVertexArray->Unbind();
#endif
			}
		}
	}
}