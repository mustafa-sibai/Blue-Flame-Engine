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
				Math::Vector3 position;
				Math::Rectangle scissorRectangle;
				unsigned int charPixelSize;

				Math::Vector2 bearing;
				Math::Vector2 advance;

				Character(Math::Vector3 position, unsigned int charPixelSize, Math::Rectangle scissorRectangle, Math::Vector2 bearing, Math::Vector2 advance) :
					position(position), charPixelSize(charPixelSize), scissorRectangle(scissorRectangle), bearing(bearing), advance(advance)
				{
				}
			};
		}
	}
}