#include "Button.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Button::Button() :
				Widget(Type::Button),
				state(State::Normal)
			{
			}

			Button::~Button()
			{
			}
		}
	}
}