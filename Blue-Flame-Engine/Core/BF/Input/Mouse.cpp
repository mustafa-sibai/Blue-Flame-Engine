#include "Mouse.h"

namespace BF
{
	namespace Input
	{
		using namespace BF::Math;

		Vector2 Mouse::positionRelativeToWindow(0.0f);
		Vector2 Mouse::positionRelativeToScreen(0.0f);
		bool Mouse::insideWindowClient = false;
		bool Mouse::buttons[MAX_BUTTONS];

		Mouse::Mouse()
		{
			for (size_t i = 0; i < MAX_BUTTONS; i++)
				buttons[i] = false;
		}

		Mouse::~Mouse()
		{
		}

		bool Mouse::IsButtonPressed(Button button)
		{
			return buttons[(unsigned char)button];
		}
	}
}