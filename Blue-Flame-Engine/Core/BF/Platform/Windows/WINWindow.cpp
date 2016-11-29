#include "WinWindow.h"
#include "BF/Input/Keyboard.h"
#include "BF/Input/Mouse.h"
#include "BF/Application/Window.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace Input;
			using namespace Application;
			using namespace Math;

			WINWindow::WINWindow(Application::Window* window) :
				window(window), hWnd(nullptr), msg(), currentWindowStyle()
			{
				HINSTANCE hInstance = GetModuleHandle(0);

				WNDCLASSEX wc;
				ZeroMemory(&wc, sizeof(wc));

				wc.cbSize = sizeof(WNDCLASSEX);
				wc.style = CS_HREDRAW | CS_VREDRAW;
				wc.lpfnWndProc = WndProc;
				wc.hInstance = hInstance;
				wc.hCursor = LoadCursor(0, IDC_ARROW);
				wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
				wc.lpszClassName = L"Blue Flame Engine Window Class";

				if (!RegisterClassEx(&wc))
					std::cout << "failed to register window class" << std::endl;

				if (window->style == WindowStyle::Windowed)
					currentWindowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;
				else if (window->style == WindowStyle::ResizableWindow)
					currentWindowStyle = WS_OVERLAPPEDWINDOW;
				else if (window->style == WindowStyle::Borderless)
					currentWindowStyle = WS_POPUP;

				wchar_t wchTitle[256];
				MultiByteToWideChar(CP_ACP, 0, window->title.c_str(), -1, wchTitle, 256);

				hWnd = CreateWindowEx(0,
					L"Blue Flame Engine Window Class",
					wchTitle,
					currentWindowStyle,
					window->positionX,
					window->positionY,
					window->width,
					window->height,
					0,
					0,
					hInstance,
					window);

				if (!hWnd)
					std::cout << "failed to create window" << std::endl;

				SetClientSize();
				ShowWindow(hWnd, SW_SHOW);
			}

			WINWindow::~WINWindow()
			{
			}

			void WINWindow::Update()
			{
				if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}

			bool WINWindow::IsOpen()
			{
				if (msg.message == WM_QUIT)
					return false;
				else
					return true;
			}

			void WINWindow::SetWindowTitle(const std::string& title)
			{
				wchar_t wchTitle[256];
				MultiByteToWideChar(CP_ACP, 0, title.c_str(), -1, wchTitle, 256);

				SetWindowText(hWnd, wchTitle);
			}

			void WINWindow::Move()
			{
				//SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP);
				//MoveWindow(hWnd, 500, 500, 100, 100, TRUE);
			}

			PIXELFORMATDESCRIPTOR WINWindow::GetPixelFormat() const
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

			void WINWindow::SetClientSize()
			{
				RECT clientRect;
				GetClientRect(hWnd, &clientRect);

				window->clientWidth = (unsigned short)clientRect.right;
				window->clientHeight = (unsigned short)clientRect.bottom;

				window->borderWidth = window->width - window->clientWidth;
				window->borderHeight = window->height - window->clientHeight;
			}

			LRESULT CALLBACK WINWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
			{
				Window *window = nullptr;

				if (message == WM_NCCREATE)
				{
					window = static_cast<Window*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

					SetLastError(0);
					if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window)))
					{
						if (GetLastError() != 0)
							return FALSE;
					}
				}
				else
					window = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

				switch (message)
				{
					case WM_DESTROY:
					{
						PostQuitMessage(0);
						break;
					}
					case WM_SIZE:
					{
						window->width = LOWORD(lParam) + window->borderWidth;
						window->height = HIWORD(lParam) + window->borderHeight;

						window->clientWidth = LOWORD(lParam);
						window->clientHeight = HIWORD(lParam);
					}
					case WM_KEYDOWN:
					{
						Keyboard::keys[(unsigned char)wParam] = true;
						break;
					}
					case WM_KEYUP:
					{
						Keyboard::keys[(unsigned char)wParam] = false;
						break;
					}
					case WM_MOUSEMOVE:
					{
						POINT mousePoint = { LOWORD(lParam), HIWORD(lParam) };
						Mouse::Position = Vector2((float)mousePoint.x, (float)mousePoint.y);
					}
					default:
						break;
				}
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
	}
}