#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLVertexBuffer
				{
				private:
					GLuint buffer;

				public:
					GLVertexBuffer();
					~GLVertexBuffer();

					void Create(const void* data, unsigned int size);
					void* Map() const;
					void Unmap() const;
					void Bind() const;
					void Unbind() const;

					inline const GLuint& GetBuffer() const { return buffer; }
				};
			}
		}
	}
}