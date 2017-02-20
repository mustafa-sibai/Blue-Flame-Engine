#pragma once
#include <string>
#include "BF/Graphics/Renderers/SpriteRenderer.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class StyleSheet;

			struct WidgetData
			{
				Renderers::Sprite normalSprite;
				Renderers::Sprite hoveredSprite;
				Renderers::Sprite pressedSprite;

				int minWidth = 0, minHeight = 0;
			};

			class BF_API Widget
			{
				friend class WidgetManager;

				protected:
					Renderers::SpriteRenderer* spriteRenderer;

				private:
					WidgetData widgetData;
					Renderers::Sprite* currentSprite;

					bool mouseNotPressedOnWidget = false;

					bool hovered;
					bool pressed;

					void(*OnClickCallBack)();

				public:
					Widget();
					~Widget();

					void AddOnClickListener(void(*OnClickCallBack)());

					void SetPosition(const Math::Vector2& position);
					void SetRectangle(Math::Rectangle rectangle);

					inline const Math::Vector2& GetPosition() const { return currentSprite->GetPosition(); }
					inline const Math::Rectangle& GetRectangle() const { return currentSprite->GetRectangle(); }

					inline bool IsHovered() const { return hovered; }
					inline bool IsPressed() const { return pressed; }

				protected:
					virtual void Initialize(Renderers::SpriteRenderer& spriteRenderer);
					virtual void Load(const StyleSheet& StyleSheet, const std::string& widgetName);
					virtual void Update();
					virtual void Render();

				private:
					bool IsMouseOnWidget();
			};
		}
	}
}