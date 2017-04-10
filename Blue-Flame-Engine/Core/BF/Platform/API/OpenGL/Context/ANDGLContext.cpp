#include "ANDGLContext.h"
#include "BF/System/Log.h"
#include "BF/Engine.h"
//#include "BF/Platform/Android/JNI.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics;

				ANDGLContext::ANDGLContext()// :
					//renderThread(&AContext::RenderLoop, this)
				{
					BF_LOG_INFO("AContext");
				}

				ANDGLContext::~ANDGLContext()
				{
					BF_LOG_INFO("~AContext");
					//renderThread.join();
				}

				void ANDGLContext::Initialize()
				{
					BF_LOG_INFO("AContext Initialize");

					const EGLint context_attrib_list[] =
					{
						EGL_CONTEXT_CLIENT_VERSION, 3,
						EGL_NONE
					};

					if (!(context = eglCreateContext(Engine::GetWindow().display, Engine::GetWindow().config, 0, context_attrib_list)))
						BF_LOG_ERROR("eglCreateContext() returned error %d", eglGetError());

					if (!eglMakeCurrent(Engine::GetWindow().display, Engine::GetWindow().surface, Engine::GetWindow().surface, context))
						BF_LOG_ERROR("eglMakeCurrent() returned error %d", eglGetError());

					if (!eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_WIDTH, &width) || !eglQuerySurface(Engine::GetWindow().display, Engine::GetWindow().surface, EGL_HEIGHT, &height))
						BF_LOG_ERROR("eglQuerySurface() returned error %d", eglGetError());

					//Engine::GetWindow().SetClientSize(width, height);

					//glDisable(GL_DITHER);
					//glViewport(0, 0, width, height);

					BF_LOG_INFO("%d %d", width, height);
					BF_LOG_INFO("OpenGLES version: %s", glGetString(GL_VERSION));
					BF_LOG_INFO("Graphics Card: %s - %s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
					BF_LOG_INFO("%s", glGetString(GL_SHADING_LANGUAGE_VERSION));
				}

				void ANDGLContext::Clear(const Color& color)
				{
					//BF_LOG_INFO("Clear");
					//glViewport(0, 0, width, height);
					glClearColor(color.r, color.g, color.b, color.a);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				}

				void ANDGLContext::Render()
				{
					//BF_LOG_INFO("Draw");
				}

				void ANDGLContext::SwapBuffers()
				{
					//BF_LOG_INFO("SwapBuffers");
					eglSwapBuffers(Engine::GetWindow().display, Engine::GetWindow().surface);
				}

				void ANDGLContext::CleanUp()
				{
					BF_LOG_INFO("CleanUp");
				}

				void ANDGLContext::RenderLoop()
				{
					BF_LOG_INFO("RenderLoop");
				}
			}
		}
	}
}