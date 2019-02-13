#pragma once
#ifdef BFE_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
	#include "BF/Platform/Windows/WINWindow.h"
#elif defined(BFE_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXWindow.h"
#elif defined(BFE_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBWindow.h"
#endif

#include <string>
#include "BF/Common.h"

#define BFE_MAX_KEYS 256

namespace BF
{
	namespace Input
	{
		class BFE_API Keyboard
		{
#ifdef BFE_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINEngineEntryPoint;
			friend class BF::Platform::Windows::WINWindow;
#elif defined(BFE_PLATFORM_LINUX)
			friend class BF::Platform::Linux::LXWindow;
#elif defined(BFE_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBWindow;
#endif

			public:
				struct Key
				{
					friend class BF::Input::Keyboard;

#ifdef BFE_PLATFORM_WINDOWS
					friend class BF::Platform::Windows::WINWindow;			
#elif defined(BFE_PLATFORM_LINUX)
					friend class BF::Platform::Linux::LXWindow;
#elif defined(BFE_PLATFORM_WEB)
					friend class BF::Platform::Web::WEBWindow;
#endif
					enum class Code
					{
#if defined (BFE_PLATFORM_WINDOWS) || defined (BFE_PLATFORM_WEB)
						Null = -0x01, Escape = 0x1B, F1 = 0x70, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, PrintScreen = 0x2C, ScrollLock = 0x91, Pause = 0x13,
						Backquote = 0xC0, Num1 = 0x31, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9, Num0 = 0x30, Minus = 0xBD, Equal = 0xBB, BackSpace = 0x08, Insert = 0x2D, Home = 0x24, PageUp = 0x21, NumLock = 0x90, NumpadDivide = 0x6F, NumpadMultiply = 0x6A, NumpadSubtract = 0x6D,
						Tab = 0x09, Q = 0x51, W = 0x57, E = 0x45, R = 0x52, T = 0x54, Y = 0x59, U = 0x55, I = 0x49, O = 0x4F, P = 0x50, OpenBracket = 0xDB, ClosedBracket = 0xDD, Backslash = 0xDC, Delete = 0x2E, End = 0x23, PageDown = 0x22, Numpad7 = 0x67, Numpad8, Numpad9, NumpadAdd = 0x6B,
						CapsLock = 0x14, A = 0x41, S = 0x53, D = 0x44, F = 0x46, G, H, J = 0x4A, K, L, Semicolon = 0xBA, Quote = 0xDE, Enter = 0x0D, Numpad4 = 0x64, Numpad5, Numpad6,
						LeftShift = 0x10, Z = 0x5A, X = 0x58, C = 0x43, V = 0x56, B = 0x42, N = 0x4E, M = 0x4D, Comma = 0xBC, Period = 0xBE, Slash, RightShift = 0x10, UpArrow = 0x26, Numpad1 = 0x61, Numpad2, Numpad3, NumpadEnter = 0x0D,
						LeftControl = 0x11, WindowKey = 0x5B, LeftAlt = 0x12, Space = 0x20, RightAlt = 0x12, Menu = 0x5D, RightControl = 0x11, LeftArrow = 0x25, DownArrow = 0x28, RightArrow = 0x27, Numpad0 = 0x60, NumpadDecimal = 0x6E
#elif defined(BFE_PLATFORM_LINUX)
						F1 = 0x43, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11 = 0x5f, F12,
						Num0 = 0x13, Num1 = 0xa, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
						NumPad0 = 0x5a, NumPad1 = 0x57, NumPad2, NumPad3, NumPad4 = 0x53, NumPad5, NumPad6, NumPad7 = 0x4f, NumPad8, NumPad9,
						A = 0x26, B = 0x38, C = 0x36, D = 0x28, E = 0x1a, F = 0x29, G = 0x2a, H = 0x2b, I = 0x1f, J = 0x2c, K = 0x2d, L = 0x2e,
						M = 0x3a, N = 0x39, O = 0x20, P = 0x21, Q = 0x18, R = 0x1b, S = 0x27, T = 0x1c, U = 0x1e, V = 0x37, W = 0x19, X = 0x35, Y = 0x1d, Z = 0x34,
						Left = 0x71, Up = 0x6f, Right = 0x72, Down = 0x74,
						CapsLock = 0x42, NumLock = 0x4d, ScrollLock = 0x4e,
						Escape = 0x09, Tab = 0x17, Enter = 0x24, Space = 0x41
#endif
					};

					private:
						enum class State { NotPressed, Pressed, HeldDown, Up };
						State state;
				};

			private:
				static Key keys[BFE_MAX_KEYS];

			public:
				Keyboard();
				~Keyboard();

				static bool IsKeyPressed(Key::Code keyCode);
				static bool IsKeyHeldDown(Key::Code  keyCode);
				static bool IsKeyUp(Key::Code  keyCode);

			private:
				static void Update();
		};
	}
}