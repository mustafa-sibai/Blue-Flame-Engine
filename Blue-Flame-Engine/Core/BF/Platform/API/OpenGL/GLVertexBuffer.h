#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include "BF/Graphics/API/VertexBufferLayout.h"
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
						GLuint VAO;
						GLuint buffer;

					public:
						GLVertexBuffer();
						~GLVertexBuffer();

						void Create(const void* data, unsigned int size);
						void SetLayout(Graphics::API::VertexBufferLayout* vertexBufferLayout);
						void* Map() const;
						void Unmap() const;
						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetBuffer() const { return buffer; }

					private:
						GLenum GetGLDataType(Graphics::API::DataType dataType);
						unsigned int GetComponentCount(Graphics::API::DataType dataType);
				};
			}
		}
	}
}