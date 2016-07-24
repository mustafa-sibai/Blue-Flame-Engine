#include "Window.h"

namespace BFE
{
	namespace Graphics
	{
		// this is the main message handler for the program
		LRESULT CALLBACK WindowProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
		{
			// sort through and find what code to run for the message given
			switch (message)
			{
				// this message is read when the window is closed
				case WM_DESTROY:
				{
					// close the application entirely
					PostQuitMessage(0);
					return 0;
				} break;
			}

			// Handle any messages the switch statement didn't
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		Window::Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Style style, Renderer::RenderingAPI rendererAPI) :
			hWnd(nullptr), msg(), mousePoint(), currentWindowStyle(), pixelFormatDesc(), width(width), height(height), clientWidth(0), clientHeight(0)
		{
			Renderer::renderingAPI = rendererAPI;

			HINSTANCE hInstance = GetModuleHandle(NULL);

			// this struct holds information for the window class
			WNDCLASSEX wc;

			// clear out the window class for use
			ZeroMemory(&wc, sizeof(WNDCLASSEX));

			// fill in the struct with the needed information
			wc.cbSize = sizeof(WNDCLASSEX);
			wc.style = CS_HREDRAW | CS_VREDRAW;
			wc.lpfnWndProc = WindowProc;
			wc.hInstance = hInstance;
			wc.hCursor = LoadCursor(NULL, IDC_ARROW);
			wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
			wc.lpszClassName = "WindowClass";

			// register the window class
			RegisterClassEx(&wc);

			if (style == Window::Style::Windowed)
				currentWindowStyle = WS_OVERLAPPEDWINDOW ^ WS_THICKFRAME;
			else if (style == Window::Style::Borderless)
				currentWindowStyle = WS_POPUP;
			 
			//Adjust the client size correctly
			RECT wr = { 0, 0, width, height };
			// set the size, but not the position
			AdjustWindowRect(&wr, currentWindowStyle, FALSE);    // adjust the size

			if (style == Window::Style::Windowed)
			{
				clientWidth = wr.right - wr.left;
				clientHeight = height + wr.top;
			}
			else if (style == Window::Style::Borderless)
			{
				clientWidth = width;
				clientHeight = height;
			}

			// create the window and use the result as the handle
			hWnd = CreateWindowEx(NULL,
				"WindowClass",    // name of the window class
				title,   // title of the window
				currentWindowStyle,    // window style
				x,    // x-position of the window
				y,    // y-position of the window
				wr.right - wr.left, // width of the window client
				wr.bottom, // height of the window client
				NULL,    // we have no parent window, NULL
				NULL,    // we aren't using menus, NULL
				hInstance,    // application handle
				NULL);    // used with multiple windows, NULL

						  /*
						  if(style == Window::Style::Borderless)
						  SetWindowLongPtr(hwnd, GWL_STYLE, WS_POPUP);*/

			// display the window on the screen
			ShowWindow(hWnd, SW_SHOW);

			std::cout << "width: " << width << " height: " << height << std::endl;
			std::cout << "width: " << clientWidth << " height: " << clientHeight << std::endl;
		}

		Window::~Window()
		{
		}

		void Window::Update()
		{
			// Check to see if any messages are waiting in the queue
			if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
			{
				// translate keystroke messages into the right format
				TranslateMessage(&msg);

				// send the message to the WindowProc function
				DispatchMessage(&msg);
			}

			if (GetCursorPos(&mousePoint))
			{
				if (ScreenToClient(hWnd, &mousePoint))
				{
					delete Input::Mouse::Position;
					Input::Mouse::Position = new Vector2((float)mousePoint.x, (float)mousePoint.y);
				}
			}
		}

		bool Window::IsOpen()
		{
			if (msg.message == WM_QUIT)
				return false;
			else
				return true;
		}

		void Window::SetWindowTitle(const char* title)
		{
			SetWindowText(hWnd, title);
		}

		void Window::Move()
		{
			//SetWindowLongPtr(hWnd, GWL_STYLE, WS_POPUP);
			//MoveWindow(hWnd, 500, 500, 100, 100, TRUE);
		}
	}
}