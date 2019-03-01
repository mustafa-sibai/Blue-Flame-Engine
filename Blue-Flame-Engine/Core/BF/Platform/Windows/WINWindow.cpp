#include "WinWindow.h"
#include "BF/Input/Controller.h"
#include "BF/Input/Keyboard.h"
#include "BF/Input/Mouse.h"
#include "BF/Math/Math.h"
#include "BF/Engine.h"
#include "BF/System/Debug.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace std;
			using namespace BF::Input;
			using namespace BF::Application;
			using namespace BF::Math;

			WINWindow::WINWindow(const string& title, const Vector2i& position, const Vector2i& clientSize, WindowStyle style) :
				Window(title, position, clientSize, style)
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
					BFE_LOG_FATAL("Failed to register window class", "");

				if (style == WindowStyle::Windowed)
					currentWindowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;
				else if (style == WindowStyle::ResizableWindow)
					currentWindowStyle = WS_OVERLAPPEDWINDOW;
				else if (style == WindowStyle::Borderless)
					currentWindowStyle = WS_POPUP;

				wchar_t wchTitle[256];
				MultiByteToWideChar(CP_ACP, 0, title.c_str(), -1, wchTitle, 256);

				borderThickness = GetSystemMetrics(SM_CXSIZEFRAME);
				RECT clientRect = { 0, 0, clientSize.x, clientSize.y };

				if (AdjustWindowRect(&clientRect, currentWindowStyle, false))
				{
					size = clientSize;
					size = Vector2i(clientRect.right - clientRect.left, clientRect.bottom - clientRect.top);
					borderSize = Vector2i(size.x - clientSize.x, size.y - clientSize.y);

					hWnd = CreateWindowEx(0,
						wc.lpszClassName,
						wchTitle,
						currentWindowStyle,
						position.x,
						position.y,
						size.x,
						size.y,
						0,
						0,
						hInstance,
						this);

					if (!hWnd)
						BFE_LOG_FATAL("Failed to create window", "");

					ShowWindow(hWnd, SW_SHOW);
				}
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
						if (mousePosition.x >= 0 && mousePosition.y >= 0 && mousePosition.x <= clientSize.x && mousePosition.y <= clientSize.y)
							Mouse::insideWindowClient = true;
						else
							Mouse::insideWindowClient = false;

						Mouse::position = Vector2f(Clamp((float)mousePosition.x, 0.0f, (float)clientSize.x), Clamp((float)mousePosition.y, 0.0f, (float)clientSize.y));
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
					Engine::state = Engine::State::Exit;
					PostQuitMessage(0);
					break;
				}
				case WM_SIZE:
				{
					window->size.x = LOWORD(lParam) + window->borderSize.x;
					window->size.y = HIWORD(lParam) + window->borderSize.y;

					window->clientSize.x = LOWORD(lParam);
					window->clientSize.y = HIWORD(lParam);

					Engine::GetContext().SetViewport(BF::Math::Rectangle(0, 0, window->clientSize.x, window->clientSize.y));
					Engine::GetContext().SetScissor(BF::Math::Rectangle(0, 0, window->clientSize.x, window->clientSize.y));
					break;
				}
				case WM_KEYDOWN:
				{
					if (Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::NotPressed)
						Keyboard::keys[(unsigned char)wParam].state = Keyboard::Key::State::Pressed;
					break;
				}
				case WM_KEYUP:
				{
					if (Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::HeldDown ||
						Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::Pressed)
						Keyboard::keys[(unsigned char)wParam].state = Keyboard::Key::State::Up;
					break;
				}
				case WM_LBUTTONDOWN:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state == Mouse::Button::State::NotPressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state = Mouse::Button::State::Pressed;
					break;
				}
				case WM_LBUTTONUP:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state == Mouse::Button::State::Pressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state = Mouse::Button::State::Up;

					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state == Mouse::Button::State::HeldDown)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Left].state = Mouse::Button::State::Up;
					break;
				}
				case WM_MBUTTONDOWN:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state == Mouse::Button::State::NotPressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state = Mouse::Button::State::Pressed;
					break;
				}
				case WM_MBUTTONUP:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state == Mouse::Button::State::Pressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state = Mouse::Button::State::Up;

					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state == Mouse::Button::State::HeldDown)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Middle].state = Mouse::Button::State::Up;
					break;
				}
				case WM_RBUTTONDOWN:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state == Mouse::Button::State::NotPressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state = Mouse::Button::State::Pressed;
					break;
				}
				case WM_RBUTTONUP:
				{
					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state == Mouse::Button::State::Pressed)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state = Mouse::Button::State::Up;

					if (Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state == Mouse::Button::State::HeldDown)
						Mouse::buttons[(unsigned char)Mouse::Button::Code::Right].state = Mouse::Button::State::Up;
					break;
				}
				case WM_XBUTTONDOWN:
				{
					int buttonID = GET_XBUTTON_WPARAM(wParam);

					if (buttonID == 1)
					{
						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state == Mouse::Button::State::NotPressed)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state = Mouse::Button::State::Pressed;
					}
					else if (buttonID == 2)
					{
						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state == Mouse::Button::State::NotPressed)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state = Mouse::Button::State::Pressed;
					}
					break;
				}
				case WM_XBUTTONUP:
				{
					int buttonID = GET_XBUTTON_WPARAM(wParam);

					if (buttonID == 1)
					{
						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state == Mouse::Button::State::Pressed)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state = Mouse::Button::State::Up;

						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state == Mouse::Button::State::HeldDown)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X1].state = Mouse::Button::State::Up;
					}
					else if (buttonID == 2)
					{
						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state == Mouse::Button::State::Pressed)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state = Mouse::Button::State::Up;

						if (Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state == Mouse::Button::State::HeldDown)
							Mouse::buttons[(unsigned char)Mouse::Button::Code::X2].state = Mouse::Button::State::Up;
					}
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