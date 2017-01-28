#pragma once
#include <iostream>
#include <Windowsx.h>
#include <Dwmapi.h>
#include "BF/Application/WindowStyle.h"
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
					unsigned short positionX, positionY, width, height, clientWidth, clientHeight, borderWidth, borderHeight;
					int borderThickness;

				public:
					WINWindow(const std::string& title, unsigned short positionX, unsigned short positionY, unsigned short width, unsigned short height, Application::WindowStyle style);
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
					inline unsigned short GetWidth() const { return width; }
					inline unsigned short GetHeight() const { return height; }

					inline unsigned short GetClientWidth() const { return clientWidth; }
					inline unsigned short GetClientHeight() const { return clientHeight; }

					inline float GetAspectRatio() const { return (float)width / (float)height; }

					inline const HWND& GetHWND() const { return hWnd; }

				private:
					static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
			};
		}
	}
}