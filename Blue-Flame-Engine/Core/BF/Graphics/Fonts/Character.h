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
				BF::Math::Rectangle scissorRectangle;

				BF::Math::Vector2i bearing;
				BF::Math::Vector2i advance;

				Character() :
					scissorRectangle(), bearing(), advance()
				{
				}

				Character(const BF::Math::Rectangle& scissorRectangle, const BF::Math::Vector2i& bearing, const BF::Math::Vector2i& advance) :
					scissorRectangle(scissorRectangle), bearing(bearing), advance(advance)
				{
				}
			};
		}
	}
}