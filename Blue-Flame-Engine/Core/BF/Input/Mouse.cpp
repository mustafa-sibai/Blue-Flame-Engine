#include "Mouse.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Input
	{
		using namespace BF::Math;

		Vector2 Mouse::position(0.0f);
		bool Mouse::insideWindowClient = false;
		bool Mouse::buttons[BF_MAX_MOUSE_BUTTONS];

		Mouse::Mouse()
		{
			for (unsigned int i = 0; i < BF_MAX_MOUSE_BUTTONS; i++)
				buttons[i] = false;
		}

		Mouse::~Mouse()
		{
		}

		bool Mouse::IsButtonPressed(Button button)
		{
			return buttons[(unsigned char)button];
		}

		void Mouse::SetPosition(Vector2 position)
		{
#ifdef BF_PLATFORM_WINDOWS
			POINT point;
			point.x = (LONG)position.x;
			point.y = (LONG)position.y;

			ClientToScreen(Engine::GetWindow().GetHWND(), &point);
			SetCursorPos(point.x, point.y);
#elif defined(BF_PLATFORM_LINUX)
#endif
		}

		void Mouse::ShowMouseCursor(bool value)
		{
#ifdef BF_PLATFORM_WINDOWS
			ShowCursor(value);
#elif defined(BF_PLATFORM_LINUX)
#endif
		}
	}
}