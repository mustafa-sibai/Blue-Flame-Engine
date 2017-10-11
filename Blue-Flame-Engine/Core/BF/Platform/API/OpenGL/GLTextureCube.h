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
				class BF_API GLTextureCube
				{
					private:
						GLuint textureID;

					public:
						GLTextureCube();
						~GLTextureCube();

						void Create(std::vector<Graphics::API::Texture::TextureData*>& textureData, Graphics::API::Texture::Format format, Graphics::API::Texture::Wrap wrap, Graphics::API::Texture::Filter filter);
						void Bind() const;
						void Unbind() const;

					private:
						int GetGLTextureFormat(Graphics::API::Texture::Format format) const;
						int GetGLTextureWrap(Graphics::API::Texture::Wrap wrap) const;
				};
			}
		}
	}
}