#include "Matrix4.h"

namespace BFE
{
	namespace Math
	{
		/*
					 m11 m12 m13 m14  x
					 m21 m22 m23 m24  y
					 m31 m32 m33 m34  z
			x y z w  m41 m42 m43 m44  w

			C++ array indices			[0,   1,   2,   3  ], [4,   5,   6,   7  ], [8,   9,   10,  11 ]  [12,  13,  14,  15 ]
			DirectX matrix layout		[m11, m21, m31, m41], [m12, m22, m32, m42], [m13, m23, m33, m43], [m14, m24, m34, m44]
			OpenGL matrix layout		[m11, m12, m13, m14], [m21, m22, m23, m24], [m31, m32, m33, m34], [m41, m42, m43, m44]
		*/

		Matrix4::Matrix4()
		{
			for (int i = 0; i < SIZE; i++)
				elements[i] = 0.0f;
		}

		Matrix4::~Matrix4()
		{
		}

		Matrix4 Matrix4::Identity()
		{
			Matrix4 identityMatrix;

			identityMatrix.elements[0 + 0 * ROW_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[1 + 1 * ROW_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[2 + 2 * ROW_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[3 + 3 * ROW_COLUMN_SIZE] = 1.0;

			return identityMatrix;
		}

		Matrix4 Matrix4::Translate(const Vector3 &translation)
		{
			Matrix4 translateMatrix = Matrix4::Identity();

			translateMatrix.elements[0 + 3 * ROW_COLUMN_SIZE] = translation.x;
			translateMatrix.elements[1 + 3 * ROW_COLUMN_SIZE] = translation.y;
			translateMatrix.elements[2 + 3 * ROW_COLUMN_SIZE] = translation.z;

			return translateMatrix;
		}

		Matrix4 Matrix4::Scale(const Vector3 &scale)
		{
			Matrix4 scaleMatrix = Matrix4::Identity();

			scaleMatrix.elements[0 + 0 * ROW_COLUMN_SIZE] = scale.x;
			scaleMatrix.elements[1 + 1 * ROW_COLUMN_SIZE] = scale.y;
			scaleMatrix.elements[2 + 2 * ROW_COLUMN_SIZE] = scale.z;

			return scaleMatrix;
		}

		Matrix4 Matrix4::Rotate(const float &angle, const Vector3 &axis)
		{
			Matrix4 RotationMatrix = Matrix4::Identity();

			float r = ToRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float oc = 1 - c;

			//First row
			RotationMatrix.elements[0 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.x * oc + c;
			RotationMatrix.elements[1 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.y * oc - axis.z * s;
			RotationMatrix.elements[2 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.z * oc + axis.y * s;

			//Second row
			RotationMatrix.elements[0 + 1 * ROW_COLUMN_SIZE] = axis.x * axis.y * oc + axis.z * s;
			RotationMatrix.elements[1 + 1 * ROW_COLUMN_SIZE] = axis.y * axis.y * oc + c;
			RotationMatrix.elements[2 + 1 * ROW_COLUMN_SIZE] = axis.y * axis.z * oc - axis.x * s;

			//Third row
			RotationMatrix.elements[0 + 2 * ROW_COLUMN_SIZE] = axis.x * axis.z * oc - axis.y * s;
			RotationMatrix.elements[1 + 2 * ROW_COLUMN_SIZE] = axis.y * axis.z * oc + axis.x * s;
			RotationMatrix.elements[2 + 2 * ROW_COLUMN_SIZE] = axis.z * axis.z * oc + c;

			return RotationMatrix;
		}

		Matrix4 Matrix4::Multiplay(const Matrix4 &leftMatrix, const Matrix4 &rightMatrix)
		{
			Matrix4 newMatrix;

			for (int y = 0; y < ROW_COLUMN_SIZE; y++)
			{
				for (int x = 0; x < ROW_COLUMN_SIZE; x++)
				{
					float Sum = 0.f;
					for (int e = 0; e < ROW_COLUMN_SIZE; e++)
						Sum += leftMatrix.elements[e + y * ROW_COLUMN_SIZE] * rightMatrix.elements[x + e * ROW_COLUMN_SIZE];

					newMatrix.elements[x + y * ROW_COLUMN_SIZE] = Sum;
				}
			}

			return newMatrix;
		}
	}
}