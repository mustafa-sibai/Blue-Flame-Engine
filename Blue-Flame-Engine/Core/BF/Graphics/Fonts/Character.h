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
				Math::Vector2 position;
				Math::Rectangle scissorRectangle;

				Math::Vector2 bearing;
				Math::Vector2 advance;

				Character(Math::Vector2 position, Math::Rectangle scissorRectangle, Math::Vector2 bearing, Math::Vector2 advance) :
					position(position), scissorRectangle(scissorRectangle), bearing(bearing), advance(advance)
				{
				}
			};
		}
	}
}