#pragma once
#include <iostream>
#include "BF/Common.h"

namespace BF
{
	namespace Graphics
	{
		struct BF_API Color
		{
			float r, g, b, a;

			Color();
			Color(float value);
			Color(float r, float g, float b, float a);
			~Color();

			friend BF_API Color operator+(const Color& left, const Color& right);
			friend BF_API Color operator-(const Color& left, const Color& right);
			friend BF_API Color operator*(const Color& left, const Color& right);
			friend BF_API Color operator/(const Color& left, const Color& right);

			Color& operator+=(const Color& right);
			Color& operator-=(const Color& right);
			Color& operator*=(const Color& right);
			Color& operator/=(const Color& right);

			friend BF_API std::ostream& operator<<(std::ostream& os, const Color& color);
		};
	}
}