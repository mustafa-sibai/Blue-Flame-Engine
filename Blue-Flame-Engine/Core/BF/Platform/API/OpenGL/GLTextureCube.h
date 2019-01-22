#pragma once
#include <vector>
#include "GLShader.h"
#include "BF/Graphics/API/Texture.h"
#include "BF/Platform/API/OpenGL/GLCommon.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BFE_API GLTextureCube
				{
				private:
					GLuint textureID;

				public:
					GLTextureCube();
					~GLTextureCube();

					void Create(std::vector<BF::Graphics::API::TextureData*>& textureData, BF::Graphics::API::Texture::Format format, BF::Graphics::API::Texture::Wrap wrap, BF::Graphics::API::Texture::Filter filter);
					void Bind() const;
					void Unbind() const;

				private:
					int GetGLTextureFormat(BF::Graphics::API::Texture::Format format) const;
					int GetGLTextureWrap(BF::Graphics::API::Texture::Wrap wrap) const;
				};
			}
		}
	}
}