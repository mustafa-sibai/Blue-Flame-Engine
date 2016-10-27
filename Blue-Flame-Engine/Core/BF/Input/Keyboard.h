#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINWindow.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/Linux/LXWindow.h"
#endif

#include "BF/Common.h"

namespace BF
{
	namespace Input
	{
		#define MAX_KEYS 256

		class BF_API Keyboard
		{
			private:
#ifdef BF_PLATFORM_WINDOWS
				friend class BF::Platform::Windows::WINWindow;
#elif BF_PLATFORM_LINUX
				friend class BF::Platform::Linux::LXWindow;
#endif
			public:
				enum class BF_API Key
				{
#ifdef BF_PLATFORM_WINDOWS
					F1 = 0x70, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
					Num0 = 0x30, Num1, Num2, Num3, Num4, Num5, Num6, Num7, Num8, Num9,
					NumPad0 = 0x60, NumPad1, NumPad2, NumPad3, NumPad4, NumPad5, NumPad6, NumPad7, NumPad8, NumPad9,
					A = 0x41, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
					Left = 0x25, Up, Right, Down,
					CapsLock = 0x14, NumLock = 0x90, ScrollLock = 0x91,
					Escape = 0x1B, Tab = 0x09, Enter = 0x0D, Space = 0x20
#elif BF_PLATFORM_LINUX
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
				static bool keys[MAX_KEYS];

			public:
				Keyboard();
				~Keyboard();

				static bool IsKeyPressed(Key key);
		};
	}
}