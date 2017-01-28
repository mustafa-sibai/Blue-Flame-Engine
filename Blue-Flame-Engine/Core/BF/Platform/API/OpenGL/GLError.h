#pragma once
#include <GL/glew.h>
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