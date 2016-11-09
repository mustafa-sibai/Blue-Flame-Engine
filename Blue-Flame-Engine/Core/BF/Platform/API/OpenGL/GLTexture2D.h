#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include "BF/IO/ImageLoader.h"
#include "BF/Math/Vector2.h"

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
						GLuint textureID;

						uint8_t* data;
						unsigned int width, height;

					public:
						GLTexture2D();
						~GLTexture2D();

						void Load(const char* fileName);

						void Bind() const;
						void Unbind() const;

						inline unsigned int GetWidth() const { return width; }
						inline unsigned int GetHeight() const { return height; }
				};
			}
		}
	}
}