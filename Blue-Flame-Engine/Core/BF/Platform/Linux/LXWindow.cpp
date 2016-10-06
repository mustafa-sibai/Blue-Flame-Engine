#ifdef BF_PLATFORM_LINUX
#include "LXWindow.h"

namespace BF
{
	namespace Platform
	{
		namespace Linux
		{
			LXWindow::LXWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style)
			{
				display = XOpenDisplay(NULL);

				if (display == NULL)
					printf("cannot connect to X server\n");

				int framebuffer_attribs[] =
				{
					GLX_X_RENDERABLE    , True,
					GLX_DRAWABLE_TYPE   , GLX_WINDOW_BIT,
					GLX_RENDER_TYPE     , GLX_RGBA_BIT,
					GLX_X_VISUAL_TYPE   , GLX_TRUE_COLOR,
					GLX_RED_SIZE        , 8,
					GLX_GREEN_SIZE      , 8,
					GLX_BLUE_SIZE       , 8,
					GLX_ALPHA_SIZE      , 8,
					GLX_DEPTH_SIZE      , 24,
					GLX_STENCIL_SIZE    , 8,
					GLX_DOUBLEBUFFER    , True,
					GLX_SAMPLE_BUFFERS  , 1,
					GLX_SAMPLES         , 4,
					None
				};

				GLenum err = glxewInit();
				if (GLEW_OK != err)
					fprintf(stderr, "Error: %s\n", glewGetErrorString(err));

				CheckGLXVersion();
				frameBufferConfig = GetBestFrameBufferConfig(framebuffer_attribs);
				CreateWindow(title, x, y, width, height, frameBufferConfig);
			}

			void LXWindow::CheckGLXVersion()
			{
				int GLXMajor, GLXMinor;

				if (!glXQueryVersion(display, &GLXMajor, &GLXMinor) || ((GLXMajor == 1) && (GLXMinor < 3)) || (GLXMajor < 1))
				{
					printf("Invalid GLX version. GLX needs to be version 1.3 or higher");
					//exit(1);
				}
			}

			GLXFBConfig LXWindow::GetBestFrameBufferConfig(int framebuffer_attribs[])
			{
				int fbcount;
				GLXFBConfig* fbc = glXChooseFBConfig(display, DefaultScreen(display), framebuffer_attribs, &fbcount);
				if (!fbc)
				{
					printf("Failed to retrieve a framebuffer config\n");
					//exit(1);
				}

				int bestFBC = -1, worstFBC = -1, bestSamples = -1, worstSamples = 999;

				size_t i;
				for (i = 0; i < fbcount; ++i)
				{
					XVisualInfo *visualInfo = glXGetVisualFromFBConfig(display, fbc[i]);
					if (visualInfo)
					{
						int sampleBuffer, samples;
						glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLE_BUFFERS, &sampleBuffer);
						glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLES, &samples);

						if (bestFBC < 0 || sampleBuffer && samples > bestSamples)
							bestFBC = i, bestSamples = samples;
						if (worstFBC < 0 || !sampleBuffer || samples < worstSamples)
							worstFBC = i, worstSamples = samples;
					}
					XFree(visualInfo);
				}

				XFree(fbc);
				return fbc[bestFBC];
			}

			void LXWindow::CreateWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, GLXFBConfig frameBuffer)
			{
				XVisualInfo *visualInfo = glXGetVisualFromFBConfig(display, frameBuffer);

				XSetWindowAttributes windowAttributes;
				Colormap colormap;
				windowAttributes.colormap = colormap = XCreateColormap(display, RootWindow(display, visualInfo->screen), visualInfo->visual, AllocNone);
				windowAttributes.background_pixmap = None;
				windowAttributes.border_pixel = 0;
				windowAttributes.event_mask = StructureNotifyMask;

				window = XCreateWindow(display, RootWindow(display, visualInfo->screen), x, y, width, height, 0,
					visualInfo->depth, InputOutput, visualInfo->visual, CWBorderPixel | CWColormap | CWEventMask, &windowAttributes);
				if (!window)
				{
					printf("Failed to create window.\n");
					//exit(1);
				}

				XFree(visualInfo);

				XStoreName(display, window, title);
				XMapWindow(display, window);
			}

			LXWindow::~LXWindow()
			{
			}

			void LXWindow::Update()
			{
			}

			bool LXWindow::IsOpen()
			{
				return true;
			}
		}
	}
}
#endif