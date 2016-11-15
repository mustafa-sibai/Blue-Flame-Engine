#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif
#include "GLShader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics { namespace API { class Texture2D; } }

	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLTexture2D
				{
					private:
						GLShader* glshader;
						Graphics::API::Texture2D* texture2D;
						GLuint textureID;

					public:
						GLTexture2D(GLShader* glshader, Graphics::API::Texture2D* texture2D);
						~GLTexture2D();

						void Create();
						void Bind() const;
						void Bind(const char* samplerName, unsigned int index) const;
						void Unbind() const;
				};
			}
		}
	}
}