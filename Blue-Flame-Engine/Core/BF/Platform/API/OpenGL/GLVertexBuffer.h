#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include "DependencyHeaders/GLEW/GL/glew.h"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "DependencyHeaders/GLES3/gl3.h"
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
						GLuint VBO;
						unsigned int size;

					public:
						GLVertexBuffer();
						~GLVertexBuffer();

						void Create(const void* data, unsigned int size);
						void SetLayout(const Graphics::API::VertexBufferLayout& vertexBufferLayout);
						void* Map() const;
						void Unmap() const;
						void Bind() const;
						void Unbind() const;

						inline const GLuint& GetBuffer() const { return VBO; }

					private:
						GLenum GetGLDataType(Graphics::API::VertexBufferLayout::DataType dataType);
						unsigned int GetComponentCount(Graphics::API::VertexBufferLayout::DataType dataType);
				};
			}
		}
	}
}