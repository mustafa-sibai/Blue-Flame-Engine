#pragma once
#include <iostream>
#include <Windows.h>
#include <Dwmapi.h>
#include "../Math/Vector4.h"
#include "../Input/Mouse.h"
#include "Renderer/Renderer.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE 
{
	namespace Graphics
	{
		class DLLEXPORT Window
		{
			public:
				enum Style
				{
					Fullscreen,
					Windowed,
					Borderless
				};

			private:
				HWND hWnd;
				MSG msg;
				POINT mousePoint;
				DWORD currentWindowStyle;
				PIXELFORMATDESCRIPTOR pixelFormatDesc;
				unsigned short width, height, clientWidth, clientHeight;
				
			public:
				Window(const char* title, unsigned short x, unsigned short y, unsigned short width, unsigned short height, Style style, Renderer::RenderingAPI rendererAPI);
				~Window();
				void Update();
				bool IsOpen();
				void Move();
				void SetWindowTitle(const char* title);

				inline unsigned short const GetWidth() const { return width; }
				inline unsigned short const GetHeight() const { return height; }

				inline unsigned short const GetClientWidth() const { return clientWidth; }
				inline unsigned short const GetClientHeight() const { return clientHeight; }

				inline HWND const &GetHWND() const { return hWnd; }
		};
	}
}