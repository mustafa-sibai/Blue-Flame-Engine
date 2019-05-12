#pragma once
#include "BF/ECS/Component.h"
#include "BF/Graphics/GUI3/WidgetState.h"
#include "BF/Common.h"

namespace BF
{
	namespace ECS
	{
		class GameObject;
	}

	namespace Graphics
	{
		namespace GUI
		{
			class StyleSheet;

			class BFE_API IWidget : public BF::ECS::Component<IWidget>
			{
				friend class BF::ECS::GameObject;
				friend class BF::Graphics::GUI::GUISystem;
				friend class BF::Graphics::GUI::StyleSheet;

			public:
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite* currentSprite;

			protected:
				enum class InternalState { Normal, Pressed, Hovered, Released };
				enum class Type { None, Button, Checkbox };

				Type type;
				InternalState internalState;
				int currentState;

				BF::Math::Vector2i minSize;
				std::vector<WidgetState> states;

			public:
				IWidget(Type type);
				IWidget(IWidget& iWidget);
				~IWidget();

				void Swap(IWidget& rhs);

				IWidget& operator=(IWidget& iWidget);
			};
		}
	}
}