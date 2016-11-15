#pragma once
#include <GL/glew.h>

#include "GLShader.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				class BF_API GLConstentBuffer
				{
					private:
						GLShader* glShader;
						GLuint buffer;

					public:
						GLConstentBuffer(GLShader* glShader);
						~GLConstentBuffer();

						void Create(unsigned int size, unsigned int bindingIndex);
						void Update(const void* data, unsigned int size);
				};
			}
		}
	}
}