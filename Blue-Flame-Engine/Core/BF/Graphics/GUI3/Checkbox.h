#pragma once
#include "BF/Graphics/GUI3/Widget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BFE_API Checkbox : public BF::Graphics::GUI::Widget<Checkbox>
			{
			public:
				enum class State { Unchecked, Checked };
				State state;

			public:
				Checkbox();
				~Checkbox();
			};
		}
	}
}