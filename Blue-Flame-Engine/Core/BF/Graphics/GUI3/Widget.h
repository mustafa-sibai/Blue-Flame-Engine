#pragma once
#include "BF/Graphics/GUI3/IWidget.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			template <class T>
			class Widget : public IWidget
			{
			public:
				Widget();
				virtual ~Widget();
			};

#include "Widget.inl"
		}
	}
}