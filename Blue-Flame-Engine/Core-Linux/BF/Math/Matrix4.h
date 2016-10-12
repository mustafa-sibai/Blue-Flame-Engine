#pragma once
#include "Math.h"
#include "../Common.h"

namespace BF
{
	namespace Math
	{
		class BF_API Matrix4
		{
			private:
				static const int ROW_COLUMN_SIZE = 4;
				static const int SIZE = ROW_COLUMN_SIZE * ROW_COLUMN_SIZE;
				float elements[SIZE];

			public:
				Matrix4();
				~Matrix4();

				static Matrix4 Identity();
				static Matrix4 Translate(const Vector3 &translation);
				static Matrix4 Scale(const Vector3 &scale);
				static Matrix4 Rotate(const float &angle, const Vector3 &axis);
				static Matrix4 Perspective(const float fieldOfView, const float aspectRatio, const float nearZ, const float farZ);

				friend const Matrix4 operator*(const Matrix4 &LeftMatrix, const Matrix4 &RightMatrix) { return Matrix4::Multiplay(LeftMatrix, RightMatrix); }

			private:
				static Matrix4 Multiplay(const Matrix4 &LeftMatrix, const Matrix4 &RightMatrix);
		};
	}
}