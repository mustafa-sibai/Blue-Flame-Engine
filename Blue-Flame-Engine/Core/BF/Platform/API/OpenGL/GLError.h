#pragma once
#include "BF/System/Debug.h"
#include "BF/Platform/API/OpenGL/GLCommon.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				std::string GetGLError(GLenum error);

#ifdef _DEBUG
#define GLCall(stmt) \
				do { stmt; \
					GLenum error = glGetError(); \
					if (error != GL_NO_ERROR) \
						BFE_LOG_ERROR("OpenGL " + GetGLError(error) + " - " + #stmt, ""); \
				} while (false)
#else
#define GLCall(stmt) stmt
#endif
			}
		}
	}
}