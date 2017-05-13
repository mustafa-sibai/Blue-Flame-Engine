#include "WEBGLContext.h"
#include "BF/Engine.h"
#include "BF/Platform/API/OpenGL/GLError.h"

#define OPENGL_CONTEXT_MAJOR_VERSION 3
#define OPENGL_CONTEXT_MINOR_VERSION 0

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				WEBGLContext::WEBGLContext()
				{
				}

				WEBGLContext::~WEBGLContext()
				{
				}

				void WEBGLContext::Initialize()
				{
					const EGLint context_attrib_list[] =
					{
						EGL_CONTEXT_CLIENT_VERSION, 2,
						EGL_NONE
					};

					if (!(context = eglCreateContext(Engine::GetWindow().display, Engine::GetWindow().config, 0, context_attrib_list)))
						BF_LOG_ERROR("eglCreateContext() returned error %d", eglGetError());

					if (!eglMakeCurrent(Engine::GetWindow().display, Engine::GetWindow().surface, Engine::GetWindow().surface, context))
						BF_LOG_ERROR("eglMakeCurrent() returned error %d", eglGetError());

					if (!eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_WIDTH, &width) || !eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_HEIGHT, &height))
						BF_LOG_ERROR("eglQuerySurface() returned error %d", eglGetError());

					Engine::GetWindow().SetClientSize(width, height);

					BF_LOG_INFO("OPENGL VERSION %s", (char*)glGetString(GL_VERSION));
					BF_LOG_INFO("Graphics Card: %s - %s", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
				}

				void WEBGLContext::SwapBuffers()
				{
					if (eglSwapInterval(Engine::GetWindow().display, 0) != EGL_TRUE)
						BF_LOG_ERROR("eglSwapInterval() returned error %d", eglGetError());
				}

				void WEBGLContext::CleanUp()
				{
				}
			}
		}
	}
}