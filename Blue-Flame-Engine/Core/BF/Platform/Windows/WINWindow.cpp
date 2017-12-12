#include "WinWindow.h"
#include "BF/Input/Controller.h"
#include "BF/Input/Keyboard.h"
#include "BF/Input/Mouse.h"
#include "BF/Math/Math.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			using namespace BF::Input;
			using namespace BF::Application;
			using namespace BF::Math;

			WINWindow::WINWindow(const std::string& title, const Math::Rectangle& rectangle, BF::Application::WindowStyle style) :
				Window(title, rectangle, style)
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
						if (mousePosition.x >= 0 && mousePosition.y >= 0 && mousePosition.x <= (int)clientWidth && mousePosition.y <= (int)clientHeight)
							Mouse::insideWindowClient = true;
						else
							Mouse::insideWindowClient = false;

						Mouse::position = Vector2f(Clamp((float)mousePosition.x, 0.0f, (float)clientWidth), Clamp((float)mousePosition.y, 0.0f, (float)clientHeight));
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
						Engine::state = Engine::State::Exit;
						PostQuitMessage(0);
						break;
					}

					case WM_SIZE:
					{
						window->rectangle.width = LOWORD(lParam) + window->borderWidth;
						window->rectangle.height = HIWORD(lParam) + window->borderHeight;

						window->clientWidth = LOWORD(lParam);
						window->clientHeight = HIWORD(lParam);

						Engine::GetContext().SetViewport(Math::Rectangle(0, 0, (int)window->clientWidth, (int)window->clientHeight));
						Engine::GetContext().SetScissor(Math::Rectangle(0, 0, (int)window->clientWidth, (int)window->clientHeight));
						break;
					}

					case WM_KEYDOWN:
					{
						if (Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::TransitionState)
							Keyboard::keys[(unsigned char)wParam].state = Keyboard::Key::State::HeldDown;

						if(Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::NotPressed)
							Keyboard::keys[(unsigned char)wParam].state = Keyboard::Key::State::Pressed;

						break;
					}

					case WM_KEYUP:
					{
						if (Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::HeldDown ||
							Keyboard::keys[(unsigned char)wParam].state == Keyboard::Key::State::TransitionState)
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