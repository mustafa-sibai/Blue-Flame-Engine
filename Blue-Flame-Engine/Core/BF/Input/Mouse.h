#pragma once
#ifdef BF_PLATFORM_WINDOWS
	#include "BF/Platform/Windows/WINEngineEntryPoint.h"
	#include "BF/Platform/Windows/WINWindow.h"
#elif defined(BF_PLATFORM_LINUX)
	#include "BF/Platform/Linux/LXWindow.h"
#elif defined(BF_PLATFORM_WEB)
	#include "BF/Platform/Web/WEBWindow.h"
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
			friend class BF::Platform::Windows::WINEngineEntryPoint;
			friend class BF::Platform::Windows::WINWindow;
#elif defined(BF_PLATFORM_WEB)
			friend class BF::Platform::Web::WEBWindow;
#endif

			public:
				struct Button
				{
					friend class BF::Input::Mouse;

#ifdef BF_PLATFORM_WINDOWS
					friend class BF::Platform::Windows::WINWindow;
#elif defined(BF_PLATFORM_LINUX)
					friend class BF::Platform::Linux::LXWindow;
#elif defined(BF_PLATFORM_WEB)
					friend class BF::Platform::Web::WEBWindow;
#endif
					enum class Code { Left, Right, Middle, X1, X2 };

				private:
					enum class State { NotPressed, Pressed, TransitionState, HeldDown, Up };
					State state;
				};

			private:
				static BF::Math::Vector2f position;
				static bool insideWindowClient;
				static Button buttons[BF_MAX_MOUSE_BUTTONS];

			public:
				Mouse();
				~Mouse();

				static bool IsButtonPressed(Button::Code buttonCode);
				static bool IsButtonHeldDown(Button::Code buttonCode);
				static bool IsButtonUp(Button::Code buttonCode);

				static void SetPosition(BF::Math::Vector2f position);

				static void ShowMouseCursor(bool value);

				inline static BF::Math::Vector2f GetPosition() { return position; }
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

			private:
				static void Update();
		};
	}
}