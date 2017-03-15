#include "WEBWindow.h"
#include "BF/System/Log.h"
#include "BF/Input/Mouse.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Platform
	{
		namespace WebGL
		{
			using namespace BF::Math;
			using namespace BF::Input;

			WEBWindow::WEBWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style) :
				Window(title, rectangle, style)
			{
			}

			WEBWindow::~WEBWindow()
			{
			}

			void WEBWindow::Initialize()
			{
				emscripten_set_canvas_size(rectangle.width, rectangle.height);

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

				if ((display = eglGetDisplay(EGL_DEFAULT_DISPLAY)) == EGL_NO_DISPLAY)
					BF_LOG_ERROR("eglGetDisplay() returned error %d", eglGetError());

				if (!eglInitialize(display, &eglMajVers, &eglMinVers))
					BF_LOG_ERROR("eglInitialize() returned error %d", eglGetError());

				if (!eglChooseConfig(display, attribs, &config, 1, &numConfigs))
					BF_LOG_ERROR("eglChooseConfig() returned error %d", eglGetError());

				if (!eglGetConfigAttrib(display, config, EGL_NATIVE_VISUAL_ID, &format))
					BF_LOG_ERROR("eglGetConfigAttrib() returned error %d", eglGetError());

				if (!(surface = eglCreateWindowSurface(display, config, nativeWindow, NULL)))
					BF_LOG_ERROR("eglCreateWindowSurface() returned error %d", eglGetError());

				BF_LOG_INFO("EGL version: %d.%d", eglMajVers, eglMinVers);

				emscripten_set_mousemove_callback(nullptr, nullptr, 1, mouseCallback);
			}

			void WEBWindow::Update()
			{
			}

			void WEBWindow::SetClientSize(int width, int height)
			{
				clientWidth = width;
				clientHeight = height;
			}

			EM_BOOL WEBWindow::mouseCallback(int eventType, const EmscriptenMouseEvent *e, void *userData)
			{
				Mouse::position = Vector2(Clamp((float)e->canvasX, 0.0f, (float)e->canvasX), Clamp((float)e->canvasY, 0.0f, (float)e->canvasY));
				return true;
			}
		}
	}
}