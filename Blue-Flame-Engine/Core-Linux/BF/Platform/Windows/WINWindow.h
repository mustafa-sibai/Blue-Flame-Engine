#pragma once
#ifdef BF_PLATFORM_WINDOWS
#include <iostream>
#include <Windows.h>
#include <Dwmapi.h>
#include "../../Common.h"
#include "../../Application/WindowStyle.h"

//#inlcude"../Math/Vector4.h"
//#include "../Input/Mouse.h"
//#include "Renderer/Renderer.h"
//#include "../RenderAPI.h"

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
					POINT mousePoint;
					DWORD currentWindowStyle;
					unsigned short width, height, clientWidth, clientHeight;

				public:
					WINWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style);
					~WINWindow();

					void Update();
					bool IsOpen();
					void Move();
					void SetWindowTitle(const char* title);

					PIXELFORMATDESCRIPTOR const GetPixelFormat() const;

					inline const unsigned short GetWidth() const { return width; }
					inline const unsigned short GetHeight() const { return height; }
						    			    
					inline const unsigned short GetClientWidth() const { return clientWidth; }
					inline const unsigned short GetClientHeight() const { return clientHeight; }

					inline const float GetAspectRatio() const { return (float)(width / height); }

					inline const HWND &GetHWND() const { return hWnd; }
			};
		}
	}
}
#endif