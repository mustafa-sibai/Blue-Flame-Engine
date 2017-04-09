#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINWindow.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/Linux/LXWindow.h"
#elif BF_PLATFORM_WEB
	#include "BF/Platform/WebGL/WEBWindow.h"
#endif

#include "BF/Math/Vector2.h"
#include "BF/Common.h"

#define BF_MAX_MOUSE_BUTTONS 10

namespace BF
{
	namespace Input
	{
		class BF_API Mouse
		{
#ifdef BF_PLATFORM_WINDOWS
			friend class BF::Platform::Windows::WINWindow;
#elif BF_PLATFORM_WEB
			friend class BF::Platform::WebGL::WEBWindow;
#endif
			private:
				static Math::Vector2 position;
				static bool insideWindowClient;
				static bool buttons[BF_MAX_MOUSE_BUTTONS];

			public:
				enum class Button { Left, Right, Middle, X1, X2 };

			public:
				Mouse();
				~Mouse();

				static bool IsButtonPressed(Button button);
				static void SetPosition(Math::Vector2 position);

				static void ShowMouseCursor(bool value);
				inline static Math::Vector2 GetPosition() { return position; }
				inline static bool IsInsideWindowClient()
				{
					if (!insideWindowClient)
						return false;

					if (insideWindowClient)
					{
						insideWindowClient = false;
						return true;
					}

					return false;
				}
		};
	}
}