#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINWindow.h"
#elif BF_PLATFORM_LINUX
	#include "BF/Platform/Linux/LXWindow.h"
#endif

#include "BF/Math/Vector2.h"
#include "BF/Common.h"

#define MAX_BUTTONS 10

namespace BF
{
	namespace Input
	{
		class BF_API Mouse
		{
			friend class BF::Platform::Windows::WINWindow;

			private:
				static Math::Vector2 positionRelativeToWindow;
				static Math::Vector2 positionRelativeToScreen;
				static bool insideWindowClient;
				static bool buttons[MAX_BUTTONS];

			public:
				enum class BF_API Button { Left, Right, Middle, X1, X2 };

			public:
				Mouse();
				~Mouse();

				static bool IsButtonPressed(Button button);

				inline static Math::Vector2 GetPositionRelativeToWindow() { return positionRelativeToWindow; }
				inline static Math::Vector2 GetPositionRelativeToScreen () { return positionRelativeToScreen; }

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