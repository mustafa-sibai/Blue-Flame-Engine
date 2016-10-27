#include "Keyboard.h"

namespace BF
{
	namespace Input
	{
		bool Keyboard::keys[MAX_KEYS];

		Keyboard::Keyboard()
		{
			for (size_t i = 0; i < MAX_KEYS; i++)
				keys[i] = false;
		}

		Keyboard::~Keyboard()
		{
		}

		bool Keyboard::IsKeyPressed(Key key)
		{
			return keys[(unsigned char)key];
		}
	}
}