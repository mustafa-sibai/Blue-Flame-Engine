#pragma once
#include <iostream>
#include <Windows.h>
#include <Dwmapi.h>
#include "BF/Common.h"
#include "BF/Application/WindowStyle.h"

namespace BF
{
	namespace Application { class Window; }
	namespace Platform
	{
		namespace Windows
		{
			class BF_API WINWindow
			{
				private:
					HWND hWnd;
					MSG msg;
					DWORD currentWindowStyle;
					Application::Window* window;

				public:
					WINWindow(Application::Window* window);
					~WINWindow();

					void Update();
					bool IsOpen();
					void Move();
					void SetWindowTitle(const char* title);
					PIXELFORMATDESCRIPTOR GetPixelFormat() const;

				private:
					void SetClientSize();

				public:
					inline const HWND& GetHWND() const { return hWnd; }

				private:
					static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			};
		}
	}
}