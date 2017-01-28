#include "Keyboard.h"

namespace BF
{
	namespace Input
	{
		bool Keyboard::keys[BF_MAX_KEYS];

		Keyboard::Keyboard()
		{
			for (unsigned int i = 0; i < BF_MAX_KEYS; i++)
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