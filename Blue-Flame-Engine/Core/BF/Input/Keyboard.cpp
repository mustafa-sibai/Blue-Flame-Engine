#include "Keyboard.h"

namespace BF
{
	namespace Input
	{
		Keyboard::Key Keyboard::keys[BF_MAX_KEYS];

		Keyboard::Keyboard()
		{
		}

		Keyboard::~Keyboard()
		{
		}

		bool Keyboard::IsKeyPressed(Key::Code keyCode)
		{
			if (keys[(unsigned char)keyCode].state == Key::State::Pressed)
			{
				keys[(unsigned char)keyCode].state = Key::State::Down;
				return true;
			}

			return false;
		}

		bool Keyboard::IsKeyDown(Key::Code keyCode)
		{
			if (keys[(unsigned char)keyCode].state == Key::State::Pressed ||
				keys[(unsigned char)keyCode].state == Key::State::Down)
			{
				keys[(unsigned char)keyCode].state = Key::State::Down;
				return true;
			}

			return false;
		}

		bool Keyboard::IsKeyUp(Key::Code keyCode)
		{
			if (keys[(unsigned char)keyCode].state == Key::State::Up)
			{
				keys[(unsigned char)keyCode].state = Key::State::Null;
				return true;
			}

			return false;
		}
	}
}