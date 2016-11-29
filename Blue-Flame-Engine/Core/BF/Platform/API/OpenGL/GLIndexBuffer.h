#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include <iostream>
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLIndexBuffer
				{
					private:
						GLuint buffer;
						unsigned int count;

					public:
						GLIndexBuffer();
						~GLIndexBuffer();

						void Create(const unsigned int* indices, unsigned int count);

						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetBuffer() const { return buffer; }
						inline unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}