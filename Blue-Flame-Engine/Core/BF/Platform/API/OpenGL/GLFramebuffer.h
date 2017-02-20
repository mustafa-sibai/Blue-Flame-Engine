#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL || defined (BF_PLATFORM_ANDROID)
	#include <GLES3/gl3.h>
#endif

#include "BF/Graphics/API/Texture2D.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLFramebuffer
				{
				private:
					const Graphics::API::Texture2D* texture2D;
					GLuint buffer;

				public:
					GLFramebuffer();
					~GLFramebuffer();

					void Create(Graphics::API::Texture2D& texture2D);

					void Bind() const;
					void Unbind() const;
				};
			}
		}
	}
}