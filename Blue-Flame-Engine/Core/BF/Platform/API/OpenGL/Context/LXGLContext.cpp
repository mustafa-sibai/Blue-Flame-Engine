#include "LXGLContext.h"
#include "BF/Engine.h"
#include "BF/Graphics/API/Context.h"
#include "BF/Platform/API/OpenGL/GLError.h"

namespace BF
{
	namespace Platform
	{
		namespace API
		{
			namespace OpenGL
			{
				using namespace BF::Graphics;
				using namespace BF::Graphics::API;

				static bool ctxErrorOccurred = false;
				static int ctxErrorHandler(Display* display, XErrorEvent* errorEvent)
				{
					ctxErrorOccurred = true;
					return 0;
				}

				LXGLContext::LXGLContext() :
					context(NULL)
				{
				}

				LXGLContext::~LXGLContext()
				{
				}

				void LXGLContext::Initialize()
				{
					// Install an X error handler so the application won't exit if GL 3.0
					// context allocation fails.
					//
					// Note this error handler is global.  All display connections in all threads
					// of a process use the same error handler, so be sure to guard against other
					// threads issuing X commands while this code is running.
					ctxErrorOccurred = false;
					int(*oldHandler)(Display*, XErrorEvent*) = XSetErrorHandler(&ctxErrorHandler);

					CreateContext(true);
					FinishCreatingContext(oldHandler);

					CreateContext(false);
					FinishCreatingContext(oldHandler);

					fprintf(stdout, "OPENGL VERSION %s\n", (char*)glGetString(GL_VERSION));
					fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
				}

				void LXGLContext::CreateContext(bool createOldContext)
				{
					if (createOldContext)
						context = glXCreateNewContext(Engine::GetWindow().GetDisplay(), Engine::GetWindow().GetFrameBufferConfig(), GLX_RGBA_TYPE, 0, True);
					else
					{
						if (glxewIsSupported("GLX_ARB_create_context"))
						{
							if (context)
							{
								glXMakeCurrent(Engine::GetWindow().GetDisplay(), 0, 0);
								glXDestroyContext(Engine::GetWindow().GetDisplay(), context);
								context = NULL;
							}

							int context_attribs[] =
							{
								GLX_CONTEXT_MAJOR_VERSION_ARB, OPENGL_CONTEXT_MAJOR_VERSION,
								GLX_CONTEXT_MINOR_VERSION_ARB, OPENGL_CONTEXT_MINOR_VERSION,
								GLX_CONTEXT_PROFILE_MASK_ARB, GLX_CONTEXT_CORE_PROFILE_BIT_ARB,
								GLX_CONTEXT_FLAGS_ARB, GLX_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
								None
							};

							context = glXCreateContextAttribsARB(Engine::GetWindow().GetDisplay(), Engine::GetWindow().GetFrameBufferConfig(), 0, True, context_attribs);
						}
						else
							printf("glXCreateContextAttribsARB() not found. Could not create new context\n");
					}
				}

				void LXGLContext::FinishCreatingContext(int(*oldHandler)(Display*, XErrorEvent*))
				{
					// Sync to ensure any errors generated are processed.
					XSync(Engine::GetWindow().GetDisplay(), False);

					// Restore the original error handler
					XSetErrorHandler(oldHandler);

					if (ctxErrorOccurred || !context)
					{
						printf("Failed to create an OpenGL context\n");
					}

					if (!glXIsDirect(Engine::GetWindow().GetDisplay(), context))
						printf("Indirect GLX rendering context obtained\n");
					else
						printf("Direct GLX rendering context obtained\n");

					glXMakeCurrent(Engine::GetWindow().GetDisplay(), Engine::GetWindow().GetXWindow(), context);

					if (!ctxErrorOccurred && context)
					{
						printf("Created GL %hu.%hu context\n", OPENGL_CONTEXT_MAJOR_VERSION, OPENGL_CONTEXT_MINOR_VERSION);
					}
					else
					{
						printf("Failed to create GL %hu.%hu context\n", OPENGL_CONTEXT_MAJOR_VERSION, OPENGL_CONTEXT_MINOR_VERSION);
					}

					GLenum err = glewInit();
					if (GLEW_OK != err)
						fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
				}

				void LXGLContext::SwapBuffers()
				{
					glXSwapBuffers(Engine::GetWindow().GetDisplay(), Engine::GetWindow().GetXWindow());
				}

				void LXGLContext::CleanUp()
				{
				}
			}
		}
	}
}