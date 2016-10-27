#pragma once
#include <string.h>
#include "Math.h"
#include "BF/Common.h"

#define MATRIX_COLUMN_SIZE 4
#define MATRIX_ROW_SIZE 4
#define MATRIX_SIZE MATRIX_COLUMN_SIZE * MATRIX_ROW_SIZE

namespace BF
{
	namespace Math
	{
		class BF_API Matrix4
		{
			private:
				float elements[MATRIX_SIZE];

			public:
				Matrix4();
				~Matrix4();

				static Matrix4 Identity();
				static Matrix4 Translate(const Vector3& translation);
				static Matrix4 Scale(const Vector3& scale);
				static Matrix4 Rotate(float angle, const Vector3& axis);
				static Matrix4 Perspective(float fieldOfView, float aspectRatio, float nearZ, float farZ);
				static Matrix4 Orthographic(float left, float right, float top, float bottom, float nearZ, float farZ);

				friend const Matrix4 operator*(const Matrix4& matrixA, const Matrix4& matrixB) { return Matrix4::Multiplay(matrixB, matrixA); }

			private:
				static Matrix4 Multiplay(const Matrix4& matrixA, const Matrix4& matrixB);
		};
	}
}