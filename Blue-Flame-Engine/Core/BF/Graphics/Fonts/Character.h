#pragma once
#include "BF/Math/Math.h"

namespace BF
{
	namespace Graphics
	{
		namespace Fonts
		{
			struct Character
			{
				Math::Vector2f position;
				Math::Rectangle scissorRectangle;

				Math::Vector2i bearing;
				Math::Vector2i advance;

				Character(const Math::Vector2f& position, const Math::Rectangle& scissorRectangle, const Math::Vector2i& bearing, const Math::Vector2i& advance) :
					position(position), scissorRectangle(scissorRectangle), bearing(bearing), advance(advance)
				{
				}
			};
		}
	}
}