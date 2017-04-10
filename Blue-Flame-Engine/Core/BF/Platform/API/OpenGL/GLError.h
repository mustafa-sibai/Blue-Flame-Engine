#pragma once
#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
	#include <GL/glew.h>
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include <GLES3/gl3.h>
#endif

#include "BF/System/Log.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				const char* GetGLError(GLenum error);

#ifdef _DEBUG
#define GLCall(stmt) \
				do { stmt; \
					GLenum error = glGetError(); \
					if (error != GL_NO_ERROR) \
						BF_LOG_ERROR("OpenGL %s - %s", GetGLError(error), #stmt); \
				} while (false)
#else
#define GLCall(stmt) stmt
#endif
			}
		}
	}
}