#pragma once
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
#include <GLES3/gl3.h>
#endif

#include "../../../Common.h"
#include "../../../IO/ImageReader.h"
#include "../../../Math/Vector2.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLTexture2D
				{
				private:
					unsigned int width, height;
					BYTE* data;
					GLuint textureID;
					GLenum image_format;
					GLint internal_format, level, border;

				public:
					GLTexture2D();
					~GLTexture2D();

					void Load(const char *fileName);
					void Bind();
					void Unbind();

					inline const unsigned int GetWidth() const { return width; }
					inline const unsigned int GetHeight() const { return height; }
				};
			}
		}
	}
}