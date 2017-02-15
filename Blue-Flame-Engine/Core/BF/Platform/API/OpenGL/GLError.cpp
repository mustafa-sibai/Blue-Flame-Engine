#include "GLError.h"
namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				const char* GetGLError(GLenum error)
				{
					switch (error)
					{
						case GL_INVALID_ENUM:      return "Invalid enum";
						case GL_INVALID_VALUE:     return "Invalid value";
						case GL_INVALID_OPERATION: return "Invalid operation";
						case GL_OUT_OF_MEMORY:     return "Out of memory";

#if defined (BF_PLATFORM_WINDOWS) || defined (BF_PLATFORM_LINUX)
						case GL_STACK_OVERFLOW:    return "Stack overflow";
						case GL_STACK_UNDERFLOW:   return "Stack underflow";
#endif
						default:                   return "Unknown error";
					}
				}
			}
		}
	}
}