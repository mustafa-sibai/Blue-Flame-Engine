#pragma once
#include "Widget.h"
#include "BF/Application/Scene.h"
#include "Scrollbar.h"
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

				Math::Vector2 contentPosition, contentLocalPosition;
				Math::Rectangle contentRectangle, contentLocalRectangle;
				Math::Rectangle scissorRectangle;

			public:
				Panel(Application::Scene& scene);
				~Panel();

				void SetPosition(const Math::Vector2& position) override;
				void SetContentLocalPosition(const Math::Vector2& contentLocalPosition);

				void SetRectangle(const Math::Rectangle& rectangle) override;
				void SetContentLocalRectangle(const Math::Rectangle& contentLocalRectangle);

				void SetScissorRectangle(Math::Rectangle scissorRectangle);

				inline const Math::Vector2& GetContentPosition() const { return contentPosition; }
				inline const Math::Vector2& GetContentLocalPosition() const { return contentLocalPosition; }

				inline const Math::Rectangle& GetContentRectangle() const { return contentRectangle; }
				inline const Math::Rectangle& GetContentLocalRectangle() const { return contentLocalRectangle; }

				inline const Math::Rectangle& GetScissorRectangle() const { return scissorRectangle; }

			protected:
				void Initialize(Renderers::SpriteRenderer& spriteRenderer) override;
				void Load(const StyleSheet& StyleSheet, const std::string& widgetName) override;
				void Update() override;
				void Render() override;

				void SetContentPosition(const Math::Vector2& contentPosition);
				void SetContentRectangle(const Math::Rectangle& contentRectangle);
			};
		}
	}
}