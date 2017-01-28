#include "TextureCube.h"
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

			TextureCube::TextureCube(const Shader& shader) :
				shader(shader)
			{
			}

			TextureCube::~TextureCube()
			{
			}

			void TextureCube::Load(const vector<string>& fileNames)
			{
				for (size_t i = 0; i < fileNames.size(); i++)
				{
					textureData.buffer = ImageLoader::Load(fileNames[i], &textureData.width, &textureData.height);
					textureCubes.push_back(textureData);
				}

#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(textureData, Format::R8G8B8A8, TextureWrap::Repeat, TextureFilter::Neatest);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Create(textureCubes, Format::R8G8B8A8, TextureWrap::Repeat, TextureFilter::Neatest);
#endif
			}

			void TextureCube::Load(const vector<string>& fileNames, TextureWrap textureWrap, TextureFilter textureFilter)
			{
				for (size_t i = 0; i < fileNames.size(); i++)
				{
					textureData.buffer = ImageLoader::Load(fileNames[i], &textureData.width, &textureData.height);
					textureCubes.push_back(textureData);
				}

#ifdef BF_PLATFORM_WINDOWS
				/*if (Context::GetRenderAPI() == RenderAPI::DirectX)
					dxTexture2D.Create(textureData, Format::R8G8B8A8, textureWrap, textureFilter);*/
#endif
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
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
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX) || defined (BF_PLATFORM_WEBGL)
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Bind();
#endif
			}

			void TextureCube::Unbind() const
			{
				if (Context::GetRenderAPI() == RenderAPI::OpenGL)
					glTextureCube.Unbind();
			}
		}
	}
}