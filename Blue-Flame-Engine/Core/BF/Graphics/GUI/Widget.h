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
				std::string name;
				Renderers::Sprite normalSprite;
				Renderers::Sprite hoveredSprite;
				Renderers::Sprite pressedSprite;
			};

			class BF_API Widget
			{
				friend class WidgetManager;

				private:
					Renderers::SpriteRenderer* spriteRenderer;
					WidgetData widgetData;
					Math::Rectangle rectangle;
					Renderers::Sprite* currentSprite;

					bool checkOnce = true;
					bool mouseNotPressedOnWidget = false;

					bool hovered;
					bool pressed;

					void(*OnClickCallBack)();

				public:
					Widget();
					~Widget();

					void AddOnClickListener(void(*OnClickCallBack)());

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