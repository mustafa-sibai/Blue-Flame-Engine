#include "AContext.h"
#include "BF/System/Log.h"
#include "BF/Engine.h"
#include "BF/Platform/Android/JNI.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				AContext::AContext()// :
					//renderThread(&AContext::RenderLoop, this)
				{
					BF_LOG_INFO("AContext");
				}

				AContext::~AContext()
				{
					BF_LOG_INFO("~AContext");
					//renderThread.join();
				}

				void AContext::Initialize()
				{
					if (Engine::GetWindow().window == nullptr)
					{
						BF_LOG_INFO("lock");
						return;
					}

					BF_LOG_INFO("AContext Initialize");
					EGLint eglMajVers, eglMinVers;

					const EGLint attribs[] = 
					{
						EGL_SURFACE_TYPE, EGL_WINDOW_BIT,
						EGL_RENDERABLE_TYPE, EGL_OPENGL_ES2_BIT,
						EGL_BLUE_SIZE, 8,
						EGL_GREEN_SIZE, 8,
						EGL_RED_SIZE, 8,
						EGL_ALPHA_SIZE, 8,
						EGL_DEPTH_SIZE, 16,
						EGL_NONE
					};

					const EGLint context_attrib_list[] = {
						EGL_CONTEXT_CLIENT_VERSION, 3,
						EGL_NONE
					};

					if ((display = eglGetDisplay(EGL_DEFAULT_DISPLAY)) == EGL_NO_DISPLAY) {
						BF_LOG_ERROR("eglGetDisplay() returned error %d", eglGetError());
						//return false;
					}

					if (!eglInitialize(display, &eglMajVers, &eglMinVers)) {
						BF_LOG_ERROR("eglInitialize() returned error %d", eglGetError());
						//return false;
					}

					BF_LOG_INFO("EGL version: %d.%d", eglMajVers, eglMinVers);

					if (!eglChooseConfig(display, attribs, &config, 1, &numConfigs)) {
						BF_LOG_ERROR("eglChooseConfig() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					if (!eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format)) {
						BF_LOG_ERROR("eglGetConfigAttrib() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					ANativeWindow_setBuffersGeometry(Engine::GetWindow().GetAWindow().window, 0, 0, format);

					if (!(surface = eglCreateWindowSurface(display, config, Engine::GetWindow().GetAWindow().window, 0))) {
						BF_LOG_ERROR("eglCreateWindowSurface() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					if (!(context = eglCreateContext(display, config, 0, context_attrib_list))) {
						BF_LOG_ERROR("eglCreateContext() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					if (!eglMakeCurrent(display, surface, surface, context)) {
						BF_LOG_ERROR("eglMakeCurrent() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					if (!eglQuerySurface(display, surface, EGL_WIDTH, &width) ||
						!eglQuerySurface(display, surface, EGL_HEIGHT, &height)) {
						BF_LOG_ERROR("eglQuerySurface() returned error %d", eglGetError());
						//destroy();
						//return false;
					}

					glDisable(GL_DITHER);
					glViewport(0, 0, width, height);

					BF_LOG_INFO("%d %d", width, height);
					BF_LOG_INFO("OpenGLES version: %s", glGetString(GL_VERSION));
					BF_LOG_INFO("Graphics Card: %s - %s\n", glGetString(GL_VENDOR), glGetString(GL_RENDERER));
					BF_LOG_INFO("%s", glGetString(GL_SHADING_LANGUAGE_VERSION));
				}

				void AContext::Clear()
				{
					glViewport(0, 0, width, height);
					glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				}

				void AContext::Draw()
				{
					BF_LOG_INFO("Draw");
				}

				void AContext::SwapBuffers()
				{
					//BF_LOG_INFO("SwapBuffers");
					eglSwapBuffers(display, surface);
				}

				void AContext::CleanUp()
				{
					BF_LOG_INFO("CleanUp");
				}

				void AContext::RenderLoop()
				{
					BF_LOG_INFO("RenderLoop");
				}
			}
		}
	}
}