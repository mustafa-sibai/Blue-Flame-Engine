#include "WinWindow.h"
#include "BF/Input/Controller.h"
#include "BF/Input/Keyboard.h"
#include "BF/Input/Mouse.h"
#include "BF/Math/Math.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace BF::Input;
			using namespace BF::Application;
			using namespace BF::Math;

			WINWindow::WINWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style) :
				title(title), rectangle(rectangle), style(style), clientWidth(0), clientHeight(0), borderWidth(0), borderHeight(0), borderThickness(0)
			{
			}

			WINWindow::~WINWindow()
			{
			}

			void WINWindow::Initialize()
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

				if (style == WindowStyle::Windowed)
					currentWindowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;
				else if (style == WindowStyle::ResizableWindow)
					currentWindowStyle = WS_OVERLAPPEDWINDOW;
				else if (style == WindowStyle::Borderless)
					currentWindowStyle = WS_POPUP;

				wchar_t wchTitle[256];
				MultiByteToWideChar(CP_ACP, 0, title.c_str(), -1, wchTitle, 256);

				borderThickness = GetSystemMetrics(SM_CXSIZEFRAME);

				hWnd = CreateWindowEx(0,
					L"Blue Flame Engine Window Class",
					wchTitle,
					currentWindowStyle,
					rectangle.x,
					rectangle.y,
					rectangle.width,
					rectangle.height,
					0,
					0,
					hInstance,
					this);

				if (!hWnd)
					std::cout << "failed to create window" << std::endl;

				SetClientSize();
				ShowWindow(hWnd, SW_SHOW);
			}

			void WINWindow::Update()
			{
				if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
				{
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				if (GetCursorPos(&mousePosition))
				{
					if (ScreenToClient(hWnd, &mousePosition))
					{
						if (mousePosition.x >= 0 && mousePosition.y >= 0 && mousePosition.x <= clientWidth && mousePosition.y <= clientHeight)
							Mouse::insideWindowClient = true;
						else
							Mouse::insideWindowClient = false;

						Mouse::position = Vector2(Clamp((float)mousePosition.x, 0.0f, (float)clientWidth), Clamp((float)mousePosition.y, 0.0f, (float)clientHeight));
					}
				}

				Controllers::Update();
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

				clientWidth = (unsigned short)clientRect.right;
				clientHeight = (unsigned short)clientRect.bottom;

				borderWidth = rectangle.width - clientWidth;
				borderHeight = rectangle.height - clientHeight;
			}

			LRESULT CALLBACK WINWindow::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
			{
				WINWindow *window = nullptr;

				if (message == WM_NCCREATE)
				{
					window = static_cast<WINWindow*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);

					SetLastError(0);
					if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(window)))
					{
						if (GetLastError() != 0)
							return FALSE;
					}
				}
				else
					window = reinterpret_cast<WINWindow*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));

				switch (message)
				{
					case WM_DESTROY:
					{
						PostQuitMessage(0);
						break;
					}

					case WM_SIZE:
					{
						window->rectangle.width = LOWORD(lParam) + window->borderWidth;
						window->rectangle.height = HIWORD(lParam) + window->borderHeight;

						window->clientWidth = LOWORD(lParam);
						window->clientHeight = HIWORD(lParam);
						break;
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

					case WM_LBUTTONDOWN:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Left] = true;
						break;
					}

					case WM_LBUTTONUP:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Left] = false;
						break;
					}

					case WM_MBUTTONDOWN:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Middle] = true;
						break;
					}

					case WM_MBUTTONUP:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Middle] = false;
						break;
					}

					case WM_RBUTTONDOWN:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Right] = true;
						break;
					}

					case WM_RBUTTONUP:
					{
						Mouse::buttons[(unsigned char)Mouse::Button::Right] = false;
						break;
					}

					case WM_XBUTTONDOWN:
					{
						int buttonID = GET_XBUTTON_WPARAM(wParam);

						if (buttonID == 1)
							Mouse::buttons[(unsigned char)Mouse::Button::X1] = true;
						else if (buttonID == 2)
							Mouse::buttons[(unsigned char)Mouse::Button::X2] = true;
						break;
					}

					case WM_XBUTTONUP:
					{
						int buttonID = GET_XBUTTON_WPARAM(wParam);

						if (buttonID == 1)
							Mouse::buttons[(unsigned char)Mouse::Button::X1] = false;
						else if (buttonID == 2)
							Mouse::buttons[(unsigned char)Mouse::Button::X2] = false;
						break;
					}

					default:
						break;
				}
				return DefWindowProc(hWnd, message, wParam, lParam);
			}
		}
	}
}