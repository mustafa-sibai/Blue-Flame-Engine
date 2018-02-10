#include "Widget.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			Widget::Widget()
			{
				Component::type = Component::Type::GUI;
			}

			Widget::~Widget()
			{
			}
		}
	}
}