#pragma once
#include "BF/Math/Math.h"
#include "BF/Common.h"

#define BFE_MATRIX_COLUMN_SIZE 4
#define BFE_MATRIX_ROW_SIZE 4
#define BFE_MATRIX_SIZE BFE_MATRIX_COLUMN_SIZE * BFE_MATRIX_ROW_SIZE

namespace BF
{
	namespace Math
	{
		class BFE_API Matrix4
		{
			private:
				float elements[BFE_MATRIX_SIZE];

			public:
				Matrix4();
				Matrix4(const Vector4f& column1, const Vector4f& column2, const Vector4f& column3, const Vector4f& column4);
				~Matrix4();

				static Matrix4 Identity();
				static Matrix4 Translate(const Vector3f& translation);
				static Matrix4 Scale(const Vector3f& scale);
				static Matrix4 Rotate(float angle, const Vector3f& axis);
				static Matrix4 Perspective(float fieldOfView, float aspectRatio, float nearZ, float farZ);
				static Matrix4 Orthographic(float left, float right, float top, float bottom, float nearZ, float farZ);
				static Matrix4 LookAt(const Vector3f& eye, const Vector3f& target, const Vector3f& up);

				inline const Matrix4& Inverse();

				inline const Vector3f GetTranslationVector() const;
				inline const Vector3f GetRotationVector() const;
				inline const Vector3f GetScaleVector() const;

				friend const Matrix4 operator*(const Matrix4& matrixA, const Matrix4& matrixB) { return Multiply(matrixB, matrixA); }

			private:
				static Matrix4 Multiply(const Matrix4& matrixA, const Matrix4& matrixB);
		};
	}
}