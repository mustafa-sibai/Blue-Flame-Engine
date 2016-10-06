#ifdef BF_PLATFORM_WINDOWS
#include "WINGLContext.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				WINGLContext::WINGLContext(Windows::WINWindow *window) :
					window(window), hDC(nullptr)
				{
					hDC = GetDC(window->GetHWND());

					int  letWindowsChooseThisPixelFormat;
					letWindowsChooseThisPixelFormat = ChoosePixelFormat(hDC, &window->GetPixelFormat());
					SetPixelFormat(hDC, letWindowsChooseThisPixelFormat, &window->GetPixelFormat());

					HGLRC tempContext = wglCreateContext(hDC);
					wglMakeCurrent(hDC, tempContext);

					int attribs[] =
					{
						WGL_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
						WGL_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,
						WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB,
						WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
					};

					GLenum err = glewInit();
					if (GLEW_OK != err)
						fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

					if (wglewIsSupported("WGL_ARB_create_context") == 1)
					{
						HGLRC context = wglCreateContextAttribsARB(hDC, 0, attribs);
						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						wglMakeCurrent(hDC, context);
					}
					else
					{
						wglMakeCurrent(NULL, NULL);
						wglDeleteContext(tempContext);
						fprintf(stdout, "Failed to create an OpenGL 3.x and above context.");
					}

					glViewport(0, 0, window->GetClientWidth(), window->GetClientHeight());

					fprintf(stdout, "OPENGL VERSION %s\n", (char*)glGetString(GL_VERSION));
					fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
				}

				WINGLContext::~WINGLContext()
				{
				}

				void WINGLContext::Clear(Math::Vector4 color)
				{
					glClearColor(color.x, color.y, color.z, color.w);
					glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
					glEnable(GL_DEPTH_TEST);
				}

				void WINGLContext::SwapBuffers()
				{
					wglSwapLayerBuffers(hDC, WGL_SWAP_MAIN_PLANE);
				}

				void WINGLContext::CleanUp()
				{
				}
			}
		}
	}
}
#endif