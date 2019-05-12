#pragma once
#include "BF/Graphics/GUI3/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BFE_API Button : public BF::Graphics::GUI::Widget<Button>
			{
			public:
				enum class State { Normal, Pressed, Hovered, Released };
				State state;

			public:
				Button();
				~Button();
			};
		}
	}
}