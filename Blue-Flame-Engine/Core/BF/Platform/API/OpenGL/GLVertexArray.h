#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif BF_PLATFORM_WEBGL
	#include <GLES3/gl3.h>
#endif

#include "BF/Graphics/API/VertexBufferLayout.h"
#include "BF/Platform/API/OpenGL/GLVertexBuffer.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLVertexArray
				{
					private:
						GLuint VAO;
						std::vector<GLVertexBuffer*>* glVertexBuffers;

					public:
						GLVertexArray();
						~GLVertexArray();

						void Create();
						void Push(GLVertexBuffer* glVertexBuffer);
						void SetVertexBufferLayout(Graphics::API::VertexBufferLayout* vertexBufferLayout);
						void Bind() const;
						void Unbind() const;

					private:
						GLenum GetGLDataType(Graphics::API::DataType dataType);
						unsigned int GetComponentCount(Graphics::API::DataType dataType);
				};
			}
		}
	}
}