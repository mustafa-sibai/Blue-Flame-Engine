#include "Keyboard.h"

namespace BF
{
	namespace Input
	{
		Keyboard::Key Keyboard::keys[BFE_MAX_KEYS];

		Keyboard::Keyboard()
		{
		}

		Keyboard::~Keyboard()
		{
		}

		bool Keyboard::IsKeyPressed(Key::Code keyCode)
		{
			return keys[(unsigned char)keyCode].state == Key::State::Pressed;
		}

		bool Keyboard::IsKeyHeldDown(Key::Code keyCode)
		{
			return keys[(unsigned char)keyCode].state == Key::State::HeldDown;
		}

		bool Keyboard::IsKeyUp(Key::Code keyCode)
		{
			return keys[(unsigned char)keyCode].state == Key::State::Up;
		}

		void Keyboard::Update()
		{
			for (size_t i = 0; i < BFE_MAX_KEYS; i++)
			{
				if (keys[i].state == Key::State::Pressed)
					keys[i].state = Key::State::HeldDown;

				if (keys[i].state == Key::State::Up)
					keys[i].state = Key::State::NotPressed;
			}
		}
	}
}