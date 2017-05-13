#if defined (BF_PLATFORM_WINDOWS)
	#include "DependencyHeaders/GLEW/GL/glew.h"
	#include "DependencyHeaders/GLEW/GL/wglew.h"
#elif defined (BF_PLATFORM_LINUX)
	#include "DependencyHeaders/GLEW/GL/glew.h"
	#include "DependencyHeaders/GLEW/GL/glxew.h"
#elif defined(BF_PLATFORM_WEB) || defined (BF_PLATFORM_ANDROID)
	#include "DependencyHeaders/EGL/egl.h"
	#include "DependencyHeaders/GLES3/gl3.h"
#endif