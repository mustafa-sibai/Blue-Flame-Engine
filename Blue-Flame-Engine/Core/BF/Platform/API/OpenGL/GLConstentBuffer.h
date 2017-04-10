#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
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
				class BF_API GLConstentBuffer
				{
					private:
						GLuint buffer;

					public:
						GLConstentBuffer();
						~GLConstentBuffer();

						void Create(unsigned int size, unsigned int bindingIndex);
						void Update(const void* data, unsigned int size);
				};
			}
		}
	}
}