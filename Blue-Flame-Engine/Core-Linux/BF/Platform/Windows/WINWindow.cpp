#ifdef BF_PLATFORM_WINDOWS
#include "WinWindow.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

			WINWindow::WINWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style) :
				hWnd(nullptr), msg(), mousePoint(), currentWindowStyle(), width(width), height(height), clientWidth(0), clientHeight(0)
			{
				HINSTANCE hInstance = GetModuleHandle(NULL);

				WNDCLASSEX wc;
				ZeroMemory(&wc, sizeof(wc));

				wc.cbSize = sizeof(WNDCLASSEX);
				wc.style = CS_HREDRAW | CS_VREDRAW;
				wc.lpfnWndProc = WndProc;
				wc.hInstance = hInstance;
				wc.hCursor = LoadCursor(NULL, IDC_ARROW);
				wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
				wc.lpszClassName = "Blue Flame Engine Window Class";

				RegisterClassEx(&wc);

				//Adjust the client size correctly
				RECT wr = { 0, 0, width, height };

				if (style == Application::WindowStyle::Windowed)
				{
					currentWindowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;

					AdjustWindowRect(&wr, currentWindowStyle, FALSE);
					clientWidth = (unsigned short)(wr.right + wr.left);
					clientHeight = (unsigned short)(height + wr.top);
				}
				else if (style == Application::WindowStyle::Borderless)
				{
					currentWindowStyle = WS_POPUP;

					AdjustWindowRect(&wr, currentWindowStyle, FALSE);
					clientWidth = width;
					clientHeight = height;
				}

				hWnd = CreateWindowEx(NULL,
					wc.lpszClassName,
					title,
					currentWindowStyle,
					x,
					y,
					wr.right - wr.left,
					wr.bottom,
					NULL,
					NULL,
					hInstance,
					NULL);

				/*
				if(style == Window::Style::Borderless)
				SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP);*/

				ShowWindow(hWnd, SW_SHOW);
			}

			WINWindow::~WINWindow()
			{
			}

			void WINWindow::Update()
			{
				if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
				/*
				if (GetCursorPos(&mousePoint))
				{
					if (ScreenToClient(hWnd, &mousePoint))
					{
						delete Input::Mouse::Position;
						Input::Mouse::Position = new Vector2((float)mousePoint.x, (float)mousePoint.y);
					}
				}*/
			}

			bool WINWindow::IsOpen()
			{
				if (msg.message == WM_QUIT)
					return false;
				else
					return true;
			}

			void WINWindow::SetWindowTitle(const char* title)
			{
				SetWindowText(hWnd, title);
			}

			void WINWindow::Move()
			{
				//SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP);
				//MoveWindow(hWnd, 500, 500, 100, 100, TRUE);
			}

			PIXELFORMATDESCRIPTOR const WINWindow::GetPixelFormat() const
			{
				PIXELFORMATDESCRIPTOR result = {};
				result.nSize = sizeof(PIXELFORMATDESCRIPTOR);
				result.nVersion = 1;
				result.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
				result.iPixelType = PFD_TYPE_RGBA;
				result.cColorBits = 32;
				result.cDepthBits = 24;
				result.cStencilBits = 8;
				result.cAuxBuffers = 0;
				result.iLayerType = PFD_MAIN_PLANE;
				return result;
			}

			LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
			{
				switch (message)
				{
				case WM_DESTROY:
				{
					PostQuitMessage(0);
					return 0;
				} break;
				}

				// Handle any messages the switch statement didn't
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
	}
}
#endif