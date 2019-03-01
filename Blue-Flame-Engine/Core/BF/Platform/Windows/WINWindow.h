#pragma once
#include <iostream>
#include <Windowsx.h>
#include <Dwmapi.h>
#include "BF/Application/Window.h"
#include "BF/Common.h"

namespace BF
{
	namespace Platform
	{
		namespace Windows
		{
			class BFE_API WINWindow : public BF::Application::Window
			{
			private:
				HWND hWnd;
				MSG msg;
				DWORD currentWindowStyle;
				POINT mousePosition;

			public:
				WINWindow(const std::string& title, const BF::Math::Vector2i& position, const BF::Math::Vector2i& clientSize, BF::Application::WindowStyle style);
				~WINWindow();

				void Initialize();
				void Update();
				bool IsOpen();
				void Move();
				void SetWindowTitle(const std::string& title);
				PIXELFORMATDESCRIPTOR GetPixelFormat() const;

				inline const HWND& GetHWND() const { return hWnd; }

			private:
				static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			};
		}
	}
}