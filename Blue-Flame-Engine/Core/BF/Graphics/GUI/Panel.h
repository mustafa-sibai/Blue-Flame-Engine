#pragma once
#include "BF/Graphics/GUI/Widget.h"
#include "BF/Graphics/GUI/Scrollbar.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class BF_API Panel : public Widget
			{
			private:
				enum class State { Normal, Resized, Moved };
				State state;

				Scrollbar horizontalScrollbar;
				Scrollbar verticalScrollbar;

				Math::Vector2f contentPosition, contentLocalPosition;
				Math::Rectangle contentRectangle, contentLocalRectangle;
				Math::Rectangle scissorRectangle;

			public:
				Panel();
				~Panel();

				void SetPosition(const Math::Vector2f& position) override;
				void SetContentLocalPosition(const Math::Vector2f& contentLocalPosition);

				void SetRectangle(const Math::Rectangle& rectangle) override;
				void SetContentLocalRectangle(const Math::Rectangle& contentLocalRectangle);

				void SetScissorRectangle(Math::Rectangle scissorRectangle);

				inline const Math::Vector2f& GetContentPosition() const { return contentPosition; }
				inline const Math::Vector2f& GetContentLocalPosition() const { return contentLocalPosition; }

				inline const Math::Rectangle& GetContentRectangle() const { return contentRectangle; }
				inline const Math::Rectangle& GetContentLocalRectangle() const { return contentLocalRectangle; }

				inline const Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }

			protected:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer) override;
				void Load(const StyleSheet& styleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;

				void SetContentPosition(const Math::Vector2f& contentPosition);
				void SetContentRectangle(const Math::Rectangle& contentRectangle);
			};
		}
	}
}