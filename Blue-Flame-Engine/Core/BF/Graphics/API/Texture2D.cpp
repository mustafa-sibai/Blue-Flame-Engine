#include "Texture2D.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace BF::IO;

			Texture2D::Texture2D(const Context* context, const Shader* shader) :
				context(context), shader(shader)
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D = new BF::Platform::API::DirectX::DXTexture2D(context->GetDXContext());
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D = new BF::Platform::API::OpenGL::GLTexture2D(shader->GetGLShader());
#endif
			}

			Texture2D::~Texture2D()
			{
			}

			void Texture2D::Load(const std::string& fileName)
			{
				buffer = ImageLoader::Load(fileName, &width, &height);

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Create(width, height, Format::R8G8B8A8, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Create(width, height, Format::R8G8B8A8, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
			}

			void Texture2D::Load(const std::string& fileName, TextureWrap textureWrap, TextureFilter textureFilter)
			{
				buffer = ImageLoader::Load(fileName, &width, &height);

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Create(width, height, Format::R8G8B8A8, buffer, textureWrap, textureFilter);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Create(width, height, Format::R8G8B8A8, buffer, textureWrap, textureFilter);
#endif
			}

			void Texture2D::Create(unsigned int width, unsigned int height, Format format, const uint8_t* data)
			{
				this->width = width;
				this->height = height;
				this->buffer = data;

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Create(width, height, format, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Create(width, height, format, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
			}

			void Texture2D::Create(unsigned int width, unsigned int height, Format format, const uint8_t* data, TextureWrap textureWrap, TextureFilter textureFilter)
			{
				this->width = width;
				this->height = height;
				this->buffer = data;

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Create(width, height, format, buffer, textureWrap, textureFilter);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Create(width, height, format, buffer, textureWrap, textureFilter);
#endif
			}

			void Texture2D::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Bind(0);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Bind();
#endif
			}

			void Texture2D::Bind(const std::string& samplerName, unsigned int index) const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D->Bind(index);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Bind(samplerName, index);
#endif
			}

			void Texture2D::Unbind() const
			{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Unbind();
#endif
			}

			void Texture2D::Unbind(const std::string& samplerName, unsigned int index) const
			{
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D->Unbind(samplerName, index);
#endif
			}
		}
	}
}