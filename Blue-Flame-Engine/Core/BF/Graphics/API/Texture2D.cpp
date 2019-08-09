#include "Texture2D.h"
#include "BF/Graphics/API/Context.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace std;

			Texture2D::Texture2D()
			{
			}

			Texture2D::~Texture2D()
			{
			}

			void Texture2D::Create(TextureData* textureData)
			{
				this->textureData = textureData;
				this->format = (Format)textureData->bitsPerPixel;
				this->wrap = Wrap::Repeat;
				this->filter = Filter::Point;

				/*//Todo: This is dirty. Create like a copy constructor or something and this should be managed by the resource manager.
				this->textureData = new TextureData(textureData.width, textureData.height, textureData.buffer);
				this->textureData->id = textureData.id;
				this->textureData->filePath = textureData.filePath;
				this->textureData->freeImage_bitmap = textureData.freeImage_bitmap;
				this->textureData->type = textureData.type;*/

#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(*textureData, (Format)textureData->bitsPerPixel, Wrap::Repeat, Filter::Point);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(*textureData, (Format)textureData->bitsPerPixel, Wrap::Repeat, Filter::Point);
#endif
			}

			void Texture2D::Create(TextureData* textureData, Wrap wrap, Filter filter)
			{
				this->textureData = textureData;
				this->format = (Format)textureData->bitsPerPixel;
				this->wrap = wrap;
				this->filter = filter;

				/*//Todo: This is dirty. Create like a copy constructor or something and this should be managed by the resource manager.
				this->textureData = new TextureData(textureData.width, textureData.height, textureData.buffer);
				this->textureData->id = textureData.id;
				this->textureData->filePath = textureData.filePath;
				this->textureData->freeImage_bitmap = textureData.freeImage_bitmap;
				this->textureData->type = textureData.type;*/

#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(*textureData, (Format)textureData->bitsPerPixel, wrap, filter);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(*textureData, (Format)textureData->bitsPerPixel, wrap, filter);
#endif
			}

			void Texture2D::Create(TextureData* textureData, Format format)
			{
				this->format = format;
				this->wrap = Wrap::Repeat;
				this->filter = Filter::Point;
				this->textureData = textureData;

				/*//Todo: This is dirty. Create like a copy constructor or something and this should be managed by the resource manager.
				this->textureData = new TextureData(textureData.width, textureData.height, textureData.buffer);
				this->textureData->id = textureData.id;
				this->textureData->filePath = textureData.filePath;
				this->textureData->freeImage_bitmap = textureData.freeImage_bitmap;
				this->textureData->type = textureData.type;*/

#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(*textureData, format, Wrap::Repeat, Filter::Point);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(*textureData, format, Wrap::Repeat, Filter::Point);
#endif
			}

			void Texture2D::Create(TextureData* textureData, Format format, Wrap wrap, Filter filter)
			{
				this->format = format;
				this->wrap = wrap;
				this->filter = filter;
				this->textureData = textureData;

				/*//Todo: This is dirty. Create like a copy constructor or something and this should be managed by the resource manager.
				this->textureData = new TextureData(textureData.width, textureData.height, textureData.buffer);
				this->textureData->id = textureData.id;
				this->textureData->filePath = textureData.filePath;
				this->textureData->freeImage_bitmap = textureData.freeImage_bitmap;
				this->textureData->type = textureData.type;*/

#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(*textureData, format, wrap, filter);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Create(*textureData, format, wrap, filter);
#endif
			}

			void Texture2D::Bind() const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Bind(0);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Bind();
#endif
			}

			void Texture2D::Bind(const Shader& shader, const string& samplerName, unsigned int index) const
			{
#ifdef BFE_PLATFORM_WINDOWS
				if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Bind(index);
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Bind(shader.glShader, samplerName, index);
#endif
			}

			void Texture2D::Unbind() const
			{

#ifdef BFE_PLATFORM_WINDOWS
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Unbind();
#endif
			}

			void Texture2D::Unbind(const string& samplerName, unsigned int index) const
			{
#ifdef BFE_PLATFORM_WINDOWS
#endif
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_LINUX) || defined (BFE_PLATFORM_WEB) || defined (BFE_PLATFORM_ANDROID)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTexture2D.Unbind(samplerName, index);
#endif
			}
		}
	}
}