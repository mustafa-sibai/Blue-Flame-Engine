#include "Texture2D.h"
#include "Context.h"
#include "BF/IO/ImageLoader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace std;
			using namespace BF::IO;

			Texture2D::Texture2D(const Shader& shader) :
				shader(shader), glTexture2D(shader.GetGLShader())
			{
			}

			Texture2D::~Texture2D()
			{
			}

			void Texture2D::Load(const string& fileName)
			{
				buffer = ImageLoader::Load(fileName, &width, &height);

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(width, height, Format::R8G8B8A8, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(width, height, Format::R8G8B8A8, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
			}

			void Texture2D::Load(const string& fileName, TextureWrap textureWrap, TextureFilter textureFilter)
			{
				buffer = ImageLoader::Load(fileName, &width, &height);

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(width, height, Format::R8G8B8A8, buffer, textureWrap, textureFilter);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(width, height, Format::R8G8B8A8, buffer, textureWrap, textureFilter);
#endif
			}

			void Texture2D::Create(unsigned int width, unsigned int height, Format format, const uint8_t* data)
			{
				this->width = width;
				this->height = height;
				this->buffer = data;

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(width, height, format, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(width, height, format, buffer, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
			}

			void Texture2D::Create(unsigned int width, unsigned int height, Format format, const uint8_t* data, TextureWrap textureWrap, TextureFilter textureFilter)
			{
				this->width = width;
				this->height = height;
				this->buffer = data;

#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(width, height, format, buffer, textureWrap, textureFilter);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(width, height, format, buffer, textureWrap, textureFilter);
#endif
			}

			void Texture2D::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Bind(0);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Bind();
#endif
			}

			void Texture2D::Bind(const string& samplerName, unsigned int index) const
			{
#ifdef BF_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Bind(index);
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Bind(samplerName, index);
#endif
			}

			void Texture2D::Unbind() const
			{
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Unbind();
			}

			void Texture2D::Unbind(const string& samplerName, unsigned int index) const
			{
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Unbind(samplerName, index);
			}
		}
	}
}