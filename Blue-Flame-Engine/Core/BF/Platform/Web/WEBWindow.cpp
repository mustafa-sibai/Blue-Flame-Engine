#include "WEBWindow.h"
#include "BF/System/Log.h"
#include "BF/Input/Mouse.h"
#include "BF/Input/Keyboard.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Platform
	{
		namespace Web
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

				emscripten_set_mousemove_callback(nullptr, nullptr, true, MouseCallback);
				emscripten_set_click_callback(nullptr, nullptr, true, MouseCallback);
				emscripten_set_mousedown_callback(nullptr, nullptr, true, MouseCallback);
				emscripten_set_mouseup_callback(nullptr, nullptr, true, MouseCallback);

				emscripten_set_keypress_callback(nullptr, nullptr, true, KeyboardCallback);
				emscripten_set_keydown_callback(nullptr, nullptr, true, KeyboardCallback);
				emscripten_set_keyup_callback(nullptr, nullptr, true, KeyboardCallback);

				//emscripten_set_dblclick_callback(0, 0, 1, mouse_callback);
			}

			void WEBWindow::Update()
			{
			}

			void WEBWindow::SetClientSize(int width, int height)
			{
				clientWidth = width;
				clientHeight = height;
			}

			EM_BOOL WEBWindow::MouseCallback(int eventType, const EmscriptenMouseEvent *e, void *userData)
			{
				//if (eventType == EMSCRIPTEN_EVENT_CLICK) gotClick = 1;
				//if (eventType == EMSCRIPTEN_EVENT_DBLCLICK) gotDblClick = 1;

				if (eventType == EMSCRIPTEN_EVENT_MOUSEDOWN)
				{
					if (e->button == 0)
						Mouse::buttons[(unsigned char)Mouse::Button::Left] = true;

					if (e->button == 1)
						Mouse::buttons[(unsigned char)Mouse::Button::Middle] = true;

					if (e->button == 2)
						Mouse::buttons[(unsigned char)Mouse::Button::Right] = true;
				}

				if (eventType == EMSCRIPTEN_EVENT_MOUSEUP)
				{
					if (e->button == 0)
						Mouse::buttons[(unsigned char)Mouse::Button::Left] = false;

					if (e->button == 1)
						Mouse::buttons[(unsigned char)Mouse::Button::Middle] = false;

					if (e->button == 2)
						Mouse::buttons[(unsigned char)Mouse::Button::Right] = false;
				}

				if (eventType == EMSCRIPTEN_EVENT_MOUSEMOVE)
					Mouse::position = Vector2(Clamp((float)e->canvasX, 0.0f, (float)e->canvasX), Clamp((float)e->canvasY, 0.0f, (float)e->canvasY));

				return true;
			}

			EM_BOOL WEBWindow::KeyboardCallback(int eventType, const EmscriptenKeyboardEvent *e, void *userData)
			{
				Keyboard::keys[e->keyCode] = false;

				if (eventType == EMSCRIPTEN_EVENT_KEYDOWN)
					Keyboard::keys[e->keyCode] = true;
				else if (eventType == EMSCRIPTEN_EVENT_KEYUP)
					Keyboard::keys[e->keyCode] = false;

				/*if ((eventType == EMSCRIPTEN_EVENT_KEYPRESS || eventType == EMSCRIPTEN_EVENT_KEYDOWN))
				{
					Keyboard::keys[*e->key] = true;
				}
				else if (eventType == EMSCRIPTEN_EVENT_KEYUP)
				{
					Keyboard::keys[*e->key] = false;
				}*/

				BF_LOG_INFO("%i-- event number: %i", e->keyCode, eventType);

				/*if (eventType == EMSCRIPTEN_EVENT_KEYPRESS)
				{
				}*/

				//only use e->which or e->keyCode
				//we will only use event 2 which is keydown
					//arrow use 2
					//other keys use 2 and 1
//#define EMSCRIPTEN_EVENT_KEYPRESS               1
//#define EMSCRIPTEN_EVENT_KEYDOWN                2
//#define EMSCRIPTEN_EVENT_KEYUP                  3
				return 0;
			}
		}
	}
}