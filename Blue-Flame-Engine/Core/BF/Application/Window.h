#pragma once
#include "BF/Application/WindowStyle.h"
#include "BF/Math/Rectangle.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BFE_API Window
		{
		protected:
			WindowStyle style;
			std::string title;
			BF::Math::Vector2i position;
			BF::Math::Vector2i size;
			BF::Math::Vector2i clientSize;
			BF::Math::Vector2i borderSize;

			int borderThickness;

		public:
			Window(const std::string& title, const BF::Math::Vector2i& position, const BF::Math::Vector2i& clientSize, WindowStyle style);
			virtual ~Window();

			inline const BF::Math::Vector2i& GetPosition() const { return position; }
			inline const BF::Math::Vector2i& GetSize() const { return size; }
			inline const BF::Math::Vector2i& GetClientSize() const { return clientSize; }

			inline float GetAspectRatio() const { return (float)clientSize.x / (float)clientSize.y; }

			inline const std::string& GetTitle() const { return title; }
			inline WindowStyle GetStyle() const { return style; }
		};
	}
}