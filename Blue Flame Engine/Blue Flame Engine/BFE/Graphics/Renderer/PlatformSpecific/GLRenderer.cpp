#include "GLRenderer.h"
#include "../../Window.h"

namespace BFE
{
	namespace Graphics
	{
		GLRenderer::GLRenderer(Window &window) :
			window(window), windowHandleToDeviceContext(nullptr)
		{
		}

		GLRenderer::~GLRenderer()
		{
		}

		void GLRenderer::Initialize()
		{
			PIXELFORMATDESCRIPTOR pixelFormatDesc =
			{
				sizeof(PIXELFORMATDESCRIPTOR),
				1,
				PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,    //Flags
				PFD_TYPE_RGBA,            //The kind of framebuffer. RGBA or palette.
				32,                        //Colordepth of the framebuffer.
				0, 0, 0, 0, 0, 0,
				0,
				0,
				0,
				0, 0, 0, 0,
				24,                        //Number of bits for the depthbuffer
				8,                        //Number of bits for the stencilbuffer
				0,                        //Number of Aux buffers in the framebuffer.
				PFD_MAIN_PLANE,
				0,
				0, 0, 0
			};

			windowHandleToDeviceContext = GetDC(window.GetHWND());

			int  letWindowsChooseThisPixelFormat;
			letWindowsChooseThisPixelFormat = ChoosePixelFormat(windowHandleToDeviceContext, &pixelFormatDesc);
			SetPixelFormat(windowHandleToDeviceContext, letWindowsChooseThisPixelFormat, &pixelFormatDesc);

			HGLRC tempContext = wglCreateContext(windowHandleToDeviceContext);
			wglMakeCurrent(windowHandleToDeviceContext, tempContext);

			int attribs[] =
			{
				WGL_CONTEXT_MAJOR_VERSION_ARB, 4,
				WGL_CONTEXT_MINOR_VERSION_ARB, 5,
				WGL_CONTEXT_FLAGS_ARB, WGL_CONTEXT_FORWARD_COMPATIBLE_BIT_ARB,
				WGL_CONTEXT_PROFILE_MASK_ARB, WGL_CONTEXT_CORE_PROFILE_BIT_ARB
			};

			if (wglewIsSupported("WGL_ARB_create_context") == 1)
			{
				tempContext = wglCreateContextAttribsARB(windowHandleToDeviceContext, 0, attribs);
				wglMakeCurrent(NULL, NULL);
				wglDeleteContext(tempContext);
				wglMakeCurrent(windowHandleToDeviceContext, tempContext);
			}
			else
			{	//It's not possible to make a GL 3.x context. Use the old style context (GL 2.1 and before)
				//tempContext = tempContext;
			}

			GLenum err = glewInit();
			if (GLEW_OK != err)
				fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

			fprintf(stdout, "OPENGL VERSION %s\n", (char*)glGetString(GL_VERSION));
			fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
		}

		void GLRenderer::Clear(Math::Vector4 Color)
		{
			glClearColor(Color.x, Color.y, Color.z, Color.w);
			glClear(GL_COLOR_BUFFER_BIT);
		}

		void GLRenderer::SwapBuffers()
		{
			wglSwapLayerBuffers(windowHandleToDeviceContext, WGL_SWAP_MAIN_PLANE);
		}

		void GLRenderer::CleanUp()
		{
		}
	}
}