#include "Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			Texture2D::Texture2D(Context* context) :
				context(context)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D = new BF::Platform::API::DirectX::DXTexture2D(context->GetDXContext());
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D = new BF::Platform::API::OpenGL::GLTexture2D();
#endif
			}

			Texture2D::~Texture2D()
			{
			}

			void Texture2D::Load(const char* fileName)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Load(fileName);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Load(fileName);
#endif
			}

			void Texture2D::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Bind();
#endif
			}

			void Texture2D::Unbind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Unbind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Unbind();
#endif
			}
		}
	}
}