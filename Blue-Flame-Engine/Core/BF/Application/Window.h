#pragma once
#include "BF/Application/WindowStyle.h"
#include "BF/Math/Rectangle.h"
#include "BF/Common.h"

namespace BF
{
	namespace Application
	{
		class BF_API Window
		{
			protected:
				WindowStyle style;
				std::string title;
				Math::Rectangle rectangle;
				unsigned int clientWidth, clientHeight, borderWidth, borderHeight;
				int borderThickness;

			public:
				Window(const std::string& title, const Math::Rectangle& rectangle, WindowStyle style);
				virtual ~Window();

				inline const Math::Rectangle& GetRectangle() const { return rectangle; }

				inline unsigned int GetClientWidth() const { return clientWidth; }
				inline unsigned int GetClientHeight() const { return clientHeight; }
				inline float GetAspectRatio() const { return (float)rectangle.width / (float)rectangle.height; }

				inline const std::string& GetTitle() const { return title; }
				inline WindowStyle GetStyle() const { return style; }
		};
	}
}