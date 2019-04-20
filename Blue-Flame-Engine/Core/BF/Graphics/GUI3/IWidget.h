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
			class BFE_API IWidget : public BF::ECS::Component<IWidget>
			{
				friend class BF::ECS::GameObject;
				friend class BF::Graphics::GUI::GUISystem;

			public:
				enum class Type { None, Button, CheckBox };

				std::vector<WidgetState> states;
				BF::Graphics::Renderers::SpriteRendererComponents::Sprite* currentSprite;
				BF::Math::Vector2i minSize;

			protected:
				Type type;

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