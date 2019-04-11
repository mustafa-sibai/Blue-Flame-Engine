#pragma once
#include "BF/Math/Rectangle.h"
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		namespace Animation
		{
			struct BFE_API KeyFrame
			{
				float time;
				BF::Math::Rectangle scissorRectangle;

				KeyFrame(float time, const BF::Math::Rectangle& scissorRectangle) :
					time(time), scissorRectangle(scissorRectangle)
				{
				}
			};
		}
	}
}