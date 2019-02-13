#pragma once
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
				class BFE_API GLTexture2D
				{
					friend class GLFramebuffer;

				private:
					GLuint textureID;
					float AFLevel;

				public:
					GLTexture2D();
					~GLTexture2D();

					void Create(const BF::Graphics::API::TextureData& textureData, BF::Graphics::API::Texture::Format format, BF::Graphics::API::Texture::Wrap wrap, BF::Graphics::API::Texture::Filter filter);
					void Bind() const;
					void Bind(const GLShader& glShader, const std::string& samplerName, unsigned int index) const;
					void Unbind() const;
					void Unbind(const std::string& samplerName, unsigned int index) const;

				private:
					int GetGLTextureFormat(BF::Graphics::API::Texture::Format format) const;
					int GetGLTextureInternalFormat(BF::Graphics::API::Texture::Format format) const;
					int GetGLTextureWrap(BF::Graphics::API::Texture::Wrap wrap) const;
				};
			}
		}
	}
}