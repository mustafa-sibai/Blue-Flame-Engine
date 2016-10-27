#include "LXWindow.h"
#include "BF/Input/Keyboard.h"
#include "BF/Application/Window.h"

namespace BF
{
	namespace Platform
	{
		namespace Linux
		{
			using namespace BF::Input;

			LXWindow::LXWindow(Application::Window* window) :
				window(window), display(nullptr), xwindow(0), xEvent(), frameBufferConfig(nullptr)
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
				CreateWindow(window, frameBufferConfig);
			}

			void LXWindow::CheckGLXVersion()
			{
				int GLXMajor, GLXMinor;

				if (!glXQueryVersion(display, &GLXMajor, &GLXMinor) || ((GLXMajor == 1) && (GLXMinor < 3)) || (GLXMajor < 1))
				{
					printf("Invalid GLX version. GLX needs to be version 1.3 or higher");
				}
			}

			GLXFBConfig LXWindow::GetBestFrameBufferConfig(int framebuffer_attribs[])
			{
				int fbcount;
				GLXFBConfig* fbc = glXChooseFBConfig(display, DefaultScreen(display), framebuffer_attribs, &fbcount);
				if (!fbc)
				{
					printf("Failed to retrieve a framebuffer config\n");
				}

				int bestFBC = -1, worstFBC = -1, bestSamples = -1, worstSamples = 999;

				int i;
				for (i = 0; i < fbcount; ++i)
				{
					XVisualInfo *visualInfo = glXGetVisualFromFBConfig(display, fbc[i]);
					if (visualInfo)
					{
						int sampleBuffer, samples;
						glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLE_BUFFERS, &sampleBuffer);
						glXGetFBConfigAttrib(display, fbc[i], GLX_SAMPLES, &samples);

						if ((bestFBC < 0 || sampleBuffer) && (samples > bestSamples))
							bestFBC = i, bestSamples = samples;
						if (worstFBC < 0 || !sampleBuffer || samples < worstSamples)
							worstFBC = i, worstSamples = samples;
					}
					XFree(visualInfo);
				}

				XFree(fbc);
				return fbc[bestFBC];
			}

			void LXWindow::CreateWindow(Application::Window* window, GLXFBConfig frameBuffer)
			{
				XVisualInfo *visualInfo = glXGetVisualFromFBConfig(display, frameBuffer);

				XSetWindowAttributes windowAttributes;
				Colormap colormap;
				windowAttributes.colormap = colormap = XCreateColormap(display, RootWindow(display, visualInfo->screen), visualInfo->visual, AllocNone);
				windowAttributes.background_pixmap = None;
				windowAttributes.border_pixel = 0;
				windowAttributes.event_mask = StructureNotifyMask;

				xwindow = XCreateWindow(display, RootWindow(display, visualInfo->screen), window->positionX, window->positionY, window->width, window->height, 0,
					visualInfo->depth, InputOutput, visualInfo->visual, CWBorderPixel | CWColormap | CWEventMask, &windowAttributes);
				if (!window)
				{
					printf("Failed to create window.\n");
				}

				XFree(visualInfo);

				XSelectInput(display, xwindow, KeyPressMask | KeyReleaseMask);

				XStoreName(display, xwindow, window->title);
				XMapWindow(display, xwindow);
			}

			LXWindow::~LXWindow()
			{
			}

			void LXWindow::Update()
			{
				while (XPending(display))
				{
					XNextEvent(display, &xEvent);
					switch (xEvent.type)
					{
						case KeyPress:
						{
							Keyboard::keys[(unsigned char)xEvent.xkey.keycode] = true;
							break;
						}
						case KeyRelease:
						{
							Keyboard::keys[(unsigned char)xEvent.xkey.keycode] = false;
							break;
						}

						default:
							break;
					}
				}

				/* close connection to server */
				//XCloseDisplay(display);
			}

			bool LXWindow::IsOpen()
			{
				return true;
			}
		}
	}
}