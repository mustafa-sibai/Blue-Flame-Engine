#pragma once
#include <string>
#include "BF/Graphics/Renderers/SpriteRenderer/SpriteRenderer.h"
#include "BF/Common.h"

#define BF_WIDGET_DATA_SPRITES_LENGTH 8

namespace BF
{
	namespace Graphics
	{
		namespace GUI
		{
			class StyleSheet;

			struct WidgetData
			{
				/*
				sprites[0] = First state normal sprite
				sprites[1] = First state hovered sprite
				sprites[2] = First state pressed sprite
				sprites[3] = First state disabled sprite

				sprites[4] = Second state normal sprite
				sprites[5] = Second state hovered sprite
				sprites[6] = Second state pressed sprite
				sprites[7] = Second state disabled sprite
				*/
				Renderers::Sprite sprites[BF_WIDGET_DATA_SPRITES_LENGTH];
				Fonts::Font* font;

				std::string text;

				enum class TextAlignment 
				{ 
					TopLeft,	TopCenter,	  TopRight,
					MiddleLeft, MiddleCenter, MiddleRight,
					BottomLeft, BottomCenter, BottomRight
				} textAlignment;

				Math::Vector2 textPosition;
				Math::Vector2 textSize;

				int minWidth = 0, minHeight = 0;
				bool renderText = false;
			};

			class BF_API Widget
			{
				friend class WidgetManager;

				protected:
					Renderers::SpriteRenderer* spriteRenderer;

				private:
					WidgetData widgetData;
					Renderers::Sprite* currentSprite;

					unsigned char currentState;

					bool mouseNotPressedOnWidget;

					bool hovered;
					bool pressed;
					bool pressedAndReleased;

					void(*OnClickCallBack)(void*);
					void* callBackPointer;

				public:
					Widget();
					~Widget();

					void AddOnClickListener(void(*OnClickCallBack)(void*), void* obj);

					virtual void SetPosition(const Math::Vector2& position);
					virtual void SetRectangle(const Math::Rectangle& rectangle);
					void SetZLayer(int zLayer);
					void SetTextAlignment(WidgetData::TextAlignment textAlignment);

					inline Math::Vector2 GetPosition() const { return currentSprite->GetPosition(); }
					inline Math::Rectangle GetRectangle() const { return currentSprite->GetRectangle(); }

					inline bool IsHovered() const { return hovered; }
					inline bool IsPressed() const { return pressed; }
					inline bool IsPressedAndReleased() const { return pressedAndReleased; }

					inline int GetZLayer() const { return currentSprite->zLayer; }

				protected:
					virtual void Initialize(Renderers::SpriteRenderer& spriteRenderer, int zLayer);
					virtual void Load(const StyleSheet& StyleSheet, const std::string& widgetName);
					virtual void Update();
					virtual void Render();

					void SwitchState();

				private:
					bool IsMouseOnWidget();
					void FireAction();
					void SetCurrentSpriteToNormal();
			};
		}
	}
}