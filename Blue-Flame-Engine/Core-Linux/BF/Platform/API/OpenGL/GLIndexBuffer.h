#pragma once
#include <iostream>
#if defined BF_PLATFORM_WINDOWS || defined BF_PLATFORM_LINUX
#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
#include <GLES3/gl3.h>
#endif
#include "../../../Common.h"

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

						void Create(const unsigned int* const indices, const unsigned int count);

						inline const GLuint &GetBuffer() const { return buffer; }

						const void Bind() const;
						const void Unbind() const;

						inline const unsigned int GetIndicesCount() const { return count; }
				};
			}
		}
	}
}