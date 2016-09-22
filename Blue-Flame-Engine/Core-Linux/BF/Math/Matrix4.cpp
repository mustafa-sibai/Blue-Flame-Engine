#include "Matrix4.h"

namespace BF
{
	namespace Math
	{
		/*
			This matrix class uses row major indexing.
			index         value       layout
			0  1  2  3    0  1  2  3    Xx Xy Xz 0
			4  5  6  7    4  5  6  7    Yx Yy Yz 0
			8  9  10 11   8  9  10 11   Zx Zy Zz 0
			12 13 14 15   12 13 14 15   Tx Ty Tz 1

			C++ array indices		[0,   1,   2,   3  ], [4,   5,   6,   7  ], [8,   9,   10,  11 ]  [12,  13,  14,  15 ]
			Row major indexing		[0,   1,   2,   3  ], [4,   5,   6,   7  ], [8,   9,   10,  11 ]  [12,  13,  14,  15 ]
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
			Matrix4 rotationMatrix = Matrix4::Identity();

			float r = ToRadians(angle);
			float c = cos(r);
			float s = sin(r);
			float oc = 1 - c;

			rotationMatrix.elements[0 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.x * oc + c;
			rotationMatrix.elements[1 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.y * oc - axis.z * s;
			rotationMatrix.elements[2 + 0 * ROW_COLUMN_SIZE] = axis.x * axis.z * oc + axis.y * s;

			rotationMatrix.elements[0 + 1 * ROW_COLUMN_SIZE] = axis.x * axis.y * oc + axis.z * s;
			rotationMatrix.elements[1 + 1 * ROW_COLUMN_SIZE] = axis.y * axis.y * oc + c;
			rotationMatrix.elements[2 + 1 * ROW_COLUMN_SIZE] = axis.y * axis.z * oc - axis.x * s;

			rotationMatrix.elements[0 + 2 * ROW_COLUMN_SIZE] = axis.x * axis.z * oc - axis.y * s;
			rotationMatrix.elements[1 + 2 * ROW_COLUMN_SIZE] = axis.y * axis.z * oc + axis.x * s;
			rotationMatrix.elements[2 + 2 * ROW_COLUMN_SIZE] = axis.z * axis.z * oc + c;

			return rotationMatrix;
		}

		Matrix4 Matrix4::Perspective(const float fieldOfView, const float aspectRatio, const float nearZ, const float farZ)
		{
			Matrix4 perspectiveMatrix = Matrix4::Identity();

			float t = 1.0f / tan(ToRadians(fieldOfView / 2.0f));

			perspectiveMatrix.elements[0 + 0 * ROW_COLUMN_SIZE] = t / aspectRatio;
			perspectiveMatrix.elements[1 + 1 * ROW_COLUMN_SIZE] = t;
			perspectiveMatrix.elements[2 + 2 * ROW_COLUMN_SIZE] = (-nearZ - farZ) / (nearZ - farZ);
			perspectiveMatrix.elements[3 + 2 * ROW_COLUMN_SIZE] = 1.0f;
			perspectiveMatrix.elements[2 + 3 * ROW_COLUMN_SIZE] = (2.0f * farZ * nearZ) / (nearZ - farZ);

			return perspectiveMatrix;
		}

		Matrix4 Matrix4::Multiplay(const Matrix4 &leftMatrix, const Matrix4 &rightMatrix)
		{
			Matrix4 newMatrix;

			for (int y = 0; y < ROW_COLUMN_SIZE; y++)
			{
				for (int e = 0; e < ROW_COLUMN_SIZE; e++)
				{
					for (int x = 0; x < ROW_COLUMN_SIZE; x++)
						newMatrix.elements[x + y * ROW_COLUMN_SIZE] += leftMatrix.elements[e + y * ROW_COLUMN_SIZE] * rightMatrix.elements[x + e * ROW_COLUMN_SIZE];
				}
			}

			return newMatrix;
		}
	}
}