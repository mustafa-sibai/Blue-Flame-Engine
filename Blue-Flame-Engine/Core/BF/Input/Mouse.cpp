#include "Mouse.h"
#include "BF/Engine.h"

namespace BF
{
	namespace Input
	{
		using namespace BF::Math;

		Vector2f Mouse::position(0.0f);
		bool Mouse::insideWindowClient = false;
		Mouse::Button Mouse::buttons[BF_MAX_MOUSE_BUTTONS];

		Mouse::Mouse()
		{
		}

		Mouse::~Mouse()
		{
		}

		bool Mouse::IsButtonPressed(Button::Code buttonCode)
		{
			return buttons[(unsigned char)buttonCode].state == Button::State::Pressed;
		}

		bool Mouse::IsButtonHeldDown(Button::Code buttonCode)
		{
			return buttons[(unsigned char)buttonCode].state == Button::State::HeldDown;
		}

		bool Mouse::IsButtonUp(Button::Code buttonCode)
		{
			return buttons[(unsigned char)buttonCode].state == Button::State::Up;
		}

		void Mouse::SetPosition(Vector2f position)
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

		void Mouse::Update()
		{
			for (size_t i = 0; i < BF_MAX_MOUSE_BUTTONS; i++)
			{
				if (buttons[i].state == Button::State::Pressed)
					buttons[i].state = Button::State::HeldDown;

				if (buttons[i].state == Button::State::Up)
					buttons[i].state = Button::State::NotPressed;
			}
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