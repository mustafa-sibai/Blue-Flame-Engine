#pragma once
#ifdef BF_PLATFORM_WINDOWS
#include <iostream>
#include <Windows.h>
#include <Dwmapi.h>
#include "../../Common.h"
#include "../../Graphics/RenderAPI.h"
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
					WINWindow(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Application::WindowStyle style, Graphics::RenderAPI renderAPI);
					~WINWindow();

					void Update();
					bool IsOpen();
					void Move();
					void SetWindowTitle(const char* title);

					PIXELFORMATDESCRIPTOR const GetPixelFormat() const;

					inline unsigned short const GetWidth() const { return width; }
					inline unsigned short const GetHeight() const { return height; }

					inline unsigned short const GetClientWidth() const { return clientWidth; }
					inline unsigned short const GetClientHeight() const { return clientHeight; }

					inline float const GetAspectRatio() const { return (float)(width / height); }

					inline HWND const &GetHWND() const { return hWnd; }
			};
		}
	}
}
#endif