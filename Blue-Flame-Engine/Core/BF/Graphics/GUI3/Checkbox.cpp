#include "Checkbox.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Checkbox::Checkbox() :
				Widget(Type::Checkbox),
				state(State::Unchecked)
			{
			}

			Checkbox::~Checkbox()
			{
			}
		}
	}
}