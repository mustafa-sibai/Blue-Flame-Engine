#pragma once
#include <iostream>
#include <Windowsx.h>
#include <Dwmapi.h>
#include "BF/Application/WindowStyle.h"
#include "BF/Math/Rectangle.h"
#include "BF/Common.h"

namespace BF
{
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
					POINT mousePosition;

					Application::WindowStyle style;
					std::string title;
					Math::Rectangle rectangle;
					unsigned int clientWidth, clientHeight, borderWidth, borderHeight;
					int borderThickness;

				public:
					WINWindow(const std::string& title, const Math::Rectangle& rectangle, Application::WindowStyle style);
					~WINWindow();

					void Initialize();
					void Update();
					bool IsOpen();
					void Move();
					void SetWindowTitle(const std::string& title);
					PIXELFORMATDESCRIPTOR GetPixelFormat() const;

				private:
					void SetClientSize();

				public:
					inline const Math::Rectangle& GetRectangle() const { return rectangle; }

					inline unsigned short GetClientWidth() const { return clientWidth; }
					inline unsigned short GetClientHeight() const { return clientHeight; }

					inline float GetAspectRatio() const { return (float)rectangle.width / (float)rectangle.height; }

					inline const HWND& GetHWND() const { return hWnd; }

				private:
					static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			};
		}
	}
}