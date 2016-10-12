#pragma once
#include <iostream>
#include <GL/glew.h>
#include "../../../Common.h"

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

						void Create(const void *data, const unsigned int size, const unsigned int bindingIndex);
						void Update(const void *data, const unsigned int size);
				};
			}
		}
	}
}