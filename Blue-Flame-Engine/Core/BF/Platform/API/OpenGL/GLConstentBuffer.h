#pragma once
#include <iostream>
#include <string.h>
#include <GL/glew.h>
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
						GLuint buffer;

					public:
						GLConstentBuffer();
						~GLConstentBuffer();

						void Create(const void* data, unsigned int size, unsigned int bindingIndex);
						void Update(const void* data, unsigned int size);
				};
			}
		}
	}
}