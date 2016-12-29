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
				Renderers::Sprite hoveredSprite;
				Renderers::Sprite pressedSprite;
				Renderers::Sprite releasedSprite;
			};

			class BF_API Widget
			{
				friend class WidgetManager;

			private:
				Renderers::SpriteRenderer* spriteRenderer;
				WidgetData widgetData;
				Math::Rectangle rectangle;

				bool checkOnce = true;
				bool mouseNotPressedOnWidget = false;

				bool hovered;
				bool pressed;
				bool released;

			public:
				Widget();
				~Widget();

				inline bool IsHovered() const { return hovered; }
				inline bool IsPressed() const { return pressed; }
				inline bool IsReleased() const { return released; }

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