#include "TextureCube.h"
#include "BF/Graphics/API/Context.h"
#include "BF/IO/ImageLoader.h"

namespace BF
{
	namespace Graphics
	{
		namespace API
		{
			using namespace std;
			using namespace BF::IO;

			TextureCube::TextureCube(const Shader& shader) :
				shader(shader)
			{
				textureCubes.reserve(6);
			}

			TextureCube::~TextureCube()
			{
			}

			void TextureCube::Load(const vector<string>& filenames)
			{
				for (size_t i = 0; i < filenames.size(); i++)
				{
					Texture::Load(filenames[i]);
					textureCubes.emplace_back(textureData);
				}

#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(textureData, Format::R8G8B8A8, TextureWrap::Repeat, TextureFilter::Neatest);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Create(textureCubes, Format::R8G8B8A8, Wrap::Repeat, Filter::Point);
#endif
			}

			void TextureCube::Load(const vector<string>& filenames, Wrap textureWrap, Filter textureFilter)
			{
				for (size_t i = 0; i < filenames.size(); i++)
				{
					Texture::Load(filenames[i]);
					textureCubes.emplace_back(textureData);
				}

#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(textureData, Format::R8G8B8A8, textureWrap, textureFilter);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Create(textureCubes, Format::R8G8B8A8, textureWrap, textureFilter);
#endif
			}

			void TextureCube::Bind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Bind(0);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Bind();
#endif
			}

			void TextureCube::Unbind() const
			{
#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
				dxTexture2D.Bind(0);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEB)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Unbind();
#endif				
			}
		}
	}
}