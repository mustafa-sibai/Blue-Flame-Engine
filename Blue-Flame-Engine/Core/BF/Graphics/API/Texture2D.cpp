#include "Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace BF::IO;

			Texture2D::Texture2D(Context* context, Shader* shader) :
				context(context), shader(shader)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D = new BF::Platform::API::DirectX::DXTexture2D(context->GetDXContext(), this);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D = new BF::Platform::API::OpenGL::GLTexture2D(shader->GetGLShader(), this);
#endif
			}

			Texture2D::~Texture2D()
			{
			}

			void Texture2D::Load(const char* fileName)
			{
				data = ImageLoader::Load(fileName, &width, &height);

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Create();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Create();
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

			void Texture2D::Bind(const char* samplerName, unsigned int index) const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Bind();
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Bind(samplerName, index);
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