#include "IWidget.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			IWidget::IWidget() :
				currentSprite(nullptr)
			{
			}

			IWidget::IWidget(IWidget& other) :
				currentSprite(nullptr), minSize(other.minSize), states(other.states)
			{
				currentSprite = &this->states[0].normal;
			}

			IWidget::~IWidget()
			{
			}

			void IWidget::Swap(IWidget& rhs)
			{
				std::swap(this->minSize, rhs.minSize);
				this->states = std::vector<WidgetState>(rhs.states);

				for (size_t i = 0; i < states.size(); i++)
				{
					states[i].normal.gameObject = gameObject;
					states[i].hovered.gameObject = gameObject;
					states[i].pressed.gameObject = gameObject;
					states[i].disabled.gameObject = gameObject;
				}

				currentSprite = &this->states[0].normal;
			}

			IWidget& IWidget::operator=(IWidget& rhs)
			{
				IWidget temp(rhs);
				Swap(temp);
				return *this;
			}
		}
	}
}