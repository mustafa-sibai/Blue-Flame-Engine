#include "WINGLContext.h"
#include "BF/Engine.h"
#include "BF/Platform/API/OpenGL/GLError.h"

#define OPENGL_CONTEXT_MAJOR_VERSION 4
#define OPENGL_CONTEXT_MINOR_VERSION 5

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				WINGLContext::WINGLContext()
				{
				}

				WINGLContext::~WINGLContext()
				{
				}

				void WINGLContext::Initialize()
				{
					hDC = GetDC(Engine::GetWindow().GetHWND());
					int letWindowsChooseThisPixelFormat = ChoosePixelFormat(hDC, &Engine::GetWindow().GetPixelFormat());
					SetPixelFormat(hDC, letWindowsChooseThisPixelFormat, &Engine::GetWindow().GetPixelFormat());

					HGLRC tempContext = wglCreateContext(hDC);
					wglMakeCurrent(hDC, tempContext);

					int attribs[] =
					{
						WGL_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
						WGL_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,
						WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
						WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
						0
					};

					GLenum err = glewInit();
					if (GLEW_OK != err)
						BFE_LOG_ERROR("Error: ", (const char*)glewGetErrorString(err));

					if (wglewIsSupported("WGL_ARB_create_context") == 1)
					{
						HGLRC context = wglCreateContextAttribsARB(hDC, 0, attribs);

						if (context == nullptr)
							BFE_LOG_FATAL("Failed to create an OpenGL context.", "");

						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						wglMakeCurrent(hDC, context);
						initialized = true;
					}
					else
					{
						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						BFE_LOG_ERROR("Failed to create an OpenGL 3.x and above context.", "");
					}

					BFE_LOG_INFO("OPENGL VERSION ", (char*)glGetString(GL_VERSION));
					BFE_LOG_INFO("Graphics Card: ", (char*)glGetString(GL_VENDOR), " - ", (char*)glGetString(GL_RENDERER));
					BFE_LOG_INFO("Status: Using GLEW ", (char*)glewGetString(GLEW_VERSION));

					GLint r;
					GLCall(glGetIntegerv(GL_MAX_TEXTURE_SIZE, &r));
					BFE_LOG_INFO(r, "");

					//SetViewport(Math::Rectangle(0, 0, (int)Engine::GetWindow().GetClientWidth(), (int)Engine::GetWindow().GetClientHeight()));
					//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
				}

				void WINGLContext::SwapBuffers()
				{
					wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE);
				}

				void WINGLContext::CleanUp()
				{
					DeleteDC(hDC);
				}

				void WINGLContext::EnableVsync(bool state)
				{
					wglSwapIntervalEXT(state);
				}
			}
		}
	}
}