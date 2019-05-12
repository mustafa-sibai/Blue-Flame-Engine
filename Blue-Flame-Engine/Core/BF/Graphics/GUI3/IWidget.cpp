#include "IWidget.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			using namespace BF::Graphics::Renderers::SpriteRendererComponents;

			IWidget::IWidget(Type type) :
				type(type), internalState(InternalState::Normal), currentState(0), currentSprite(new Sprite(nullptr, nullptr))
			{
				IComponent::type = IComponent::Type::Widget;
			}

			IWidget::IWidget(IWidget& other) :
				type(other.type), internalState(other.internalState), currentState(other.currentState), currentSprite(other.currentSprite), minSize(other.minSize), states(other.states)
			{
				*currentSprite = this->states[0].normal;
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

				*currentSprite = this->states[0].normal;
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