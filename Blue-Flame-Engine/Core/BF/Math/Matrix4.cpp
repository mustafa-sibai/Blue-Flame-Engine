#include "Matrix4.h"
#include <string.h>

namespace BF
{
	namespace Math
	{
		/*
			This matrix class uses column major memory layout with column major vectors.
			This class assums you will do your matrix and vector multiplication in this order.
			M = Iv
			Where M is the new matrix. I is the identity matrix. v is the vector matrix.
			This will match both DirectX and OpenGL column major memory layout and will use column major vector in the shader.

			This matrix class also uses a left handed coordinates system.

			index         value                 layout
			0  4  8  12   M11  M12  M13  M14    Xx Yx Zz Tx
			1  5  9  13   M21  M22  M23  M24    Xy Yy Zy Ty
			2  6  10 14   M31  M32  M33  M34    Xz Yz Zz Tz
			3  7  11 15   M41  M42  M43  M44    0  0  0  1

			C++ array indices		[0,   1,   2,   3  ], [4,   5,   6,   7  ], [8,   9,   10,  11 ]  [12,  13,  14,  15 ]
			Column major indexing	[M11, M21, M31, M41], [M12, M22, M32, M42], [M13, M23, M33, M43]  [M14, M24, M34, M44]
		*/

		Matrix4::Matrix4()
		{
			memset(elements, 0, sizeof(float) * BFE_MATRIX_SIZE);
		}

		Matrix4::Matrix4(const Vector4f& column1, const Vector4f& column2, const Vector4f& column3, const Vector4f& column4)
		{
			elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = column1.x;
			elements[1 + 0 * BFE_MATRIX_COLUMN_SIZE] = column1.y;
			elements[2 + 0 * BFE_MATRIX_COLUMN_SIZE] = column1.z;
			elements[3 + 0 * BFE_MATRIX_COLUMN_SIZE] = column1.w;

			elements[0 + 1 * BFE_MATRIX_COLUMN_SIZE] = column2.x;
			elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = column2.y;
			elements[2 + 1 * BFE_MATRIX_COLUMN_SIZE] = column2.z;
			elements[3 + 1 * BFE_MATRIX_COLUMN_SIZE] = column2.w;

			elements[0 + 2 * BFE_MATRIX_COLUMN_SIZE] = column3.x;
			elements[1 + 2 * BFE_MATRIX_COLUMN_SIZE] = column3.y;
			elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = column3.z;
			elements[3 + 2 * BFE_MATRIX_COLUMN_SIZE] = column3.w;

			elements[0 + 3 * BFE_MATRIX_COLUMN_SIZE] = column4.x;
			elements[1 + 3 * BFE_MATRIX_COLUMN_SIZE] = column4.y;
			elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE] = column4.z;
			elements[3 + 3 * BFE_MATRIX_COLUMN_SIZE] = column4.w;
		}

		Matrix4::~Matrix4()
		{
		}

		Matrix4 Matrix4::Identity()
		{
			Matrix4 identityMatrix;

			identityMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = 1.0;
			identityMatrix.elements[3 + 3 * BFE_MATRIX_COLUMN_SIZE] = 1.0;

			return identityMatrix;
		}

		Matrix4 Matrix4::Translate(const Vector3f& translation)
		{
			Matrix4 translateMatrix = Matrix4::Identity();

			translateMatrix.elements[0 + 3 * BFE_MATRIX_COLUMN_SIZE] = translation.x;
			translateMatrix.elements[1 + 3 * BFE_MATRIX_COLUMN_SIZE] = translation.y;
			translateMatrix.elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE] = translation.z;

			return translateMatrix;
		}

		Matrix4 Matrix4::Scale(const Vector3f& scale)
		{
			Matrix4 scaleMatrix = Matrix4::Identity();

			scaleMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = scale.x;
			scaleMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = scale.y;
			scaleMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = scale.z;

			return scaleMatrix;
		}

		Matrix4 Matrix4::Rotate(float angle, const Vector3f& axis)
		{
			Matrix4 rotationMatrix = Matrix4::Identity();

			float r = ToRadians(angle);
			float c = (float)cos(r);
			float s = (float)sin(r);
			float oc = 1.0f - c;

			rotationMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = axis.x * axis.x * oc + c;
			rotationMatrix.elements[1 + 0 * BFE_MATRIX_COLUMN_SIZE] = axis.x * axis.y * oc + axis.z * s;
			rotationMatrix.elements[2 + 0 * BFE_MATRIX_COLUMN_SIZE] = axis.x * axis.z * oc - axis.y * s;

			rotationMatrix.elements[0 + 1 * BFE_MATRIX_COLUMN_SIZE] = axis.x * axis.y * oc - axis.z * s;
			rotationMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = axis.y * axis.y * oc + c;
			rotationMatrix.elements[2 + 1 * BFE_MATRIX_COLUMN_SIZE] = axis.y * axis.z * oc + axis.x * s;

			rotationMatrix.elements[0 + 2 * BFE_MATRIX_COLUMN_SIZE] = axis.x * axis.z * oc + axis.y * s;
			rotationMatrix.elements[1 + 2 * BFE_MATRIX_COLUMN_SIZE] = axis.y * axis.z * oc - axis.x * s;
			rotationMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = axis.z * axis.z * oc + c;

			return rotationMatrix;
		}

		Matrix4 Matrix4::Perspective(float fieldOfView, float aspectRatio, float nearZ, float farZ)
		{
			Matrix4 perspectiveMatrix;

			float t = (float)tan(ToRadians(fieldOfView * 0.5f));

			perspectiveMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = 1.0f / (t * aspectRatio);
			perspectiveMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = 1.0f / t;
			perspectiveMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = (-nearZ - farZ) / (nearZ - farZ);
			perspectiveMatrix.elements[3 + 2 * BFE_MATRIX_COLUMN_SIZE] = 1.0f;
			perspectiveMatrix.elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE] = (2.0f * farZ * nearZ) / (nearZ - farZ);

			return perspectiveMatrix;
		}

		Matrix4 Matrix4::Orthographic(float left, float right, float top, float bottom, float nearZ, float farZ)
		{
			Matrix4 orthographicMatrix = Identity();

			orthographicMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = 2.0f / (right - left);
			orthographicMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = 2.0f / (top - bottom);
			orthographicMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = -2.0f / (farZ - nearZ);
			orthographicMatrix.elements[0 + 3 * BFE_MATRIX_COLUMN_SIZE] = -((right + left) / (right - left));
			orthographicMatrix.elements[1 + 3 * BFE_MATRIX_COLUMN_SIZE] = -((top + bottom) / (top - bottom));
			orthographicMatrix.elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE] = -((farZ + nearZ) / (farZ - nearZ));

			return orthographicMatrix;
		}

		Matrix4 Matrix4::LookAt(const Vector3f& eye, const Vector3f& target, const Vector3f& upVector)
		{
			Matrix4 viewMatrix = Matrix4::Identity();

			Vector3f forward = (target - eye).Normalize();
			Vector3f right = upVector.Cross(forward).Normalize();
			Vector3f up = forward.Cross(right);

			viewMatrix.elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE] = right.x;
			viewMatrix.elements[0 + 1 * BFE_MATRIX_COLUMN_SIZE] = right.y;
			viewMatrix.elements[0 + 2 * BFE_MATRIX_COLUMN_SIZE] = right.z;

			viewMatrix.elements[1 + 0 * BFE_MATRIX_COLUMN_SIZE] = up.x;
			viewMatrix.elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE] = up.y;
			viewMatrix.elements[1 + 2 * BFE_MATRIX_COLUMN_SIZE] = up.z;

			viewMatrix.elements[2 + 0 * BFE_MATRIX_COLUMN_SIZE] = forward.x;
			viewMatrix.elements[2 + 1 * BFE_MATRIX_COLUMN_SIZE] = forward.y;
			viewMatrix.elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE] = forward.z;

			viewMatrix.elements[0 + 3 * BFE_MATRIX_COLUMN_SIZE] = -right.Dot(eye);
			viewMatrix.elements[1 + 3 * BFE_MATRIX_COLUMN_SIZE] = -up.Dot(eye);
			viewMatrix.elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE] = -forward.Dot(eye);

			return viewMatrix;
		}

		inline const Matrix4& Matrix4::Inverse()
		{
			float temp[16];

			temp[0] =	elements[5]  * elements[10] * elements[15] -
						elements[5]  * elements[11] * elements[14] -
						elements[9]  * elements[6]  * elements[15] +
						elements[9]  * elements[7]  * elements[14] +
						elements[13] * elements[6]  * elements[11] -
						elements[13] * elements[7]  * elements[10];

			temp[4] =  -elements[4]  * elements[10] * elements[15] +
						elements[4]  * elements[11] * elements[14] +
						elements[8]  * elements[6]  * elements[15] -
						elements[8]  * elements[7]  * elements[14] -
						elements[12] * elements[6]  * elements[11] +
						elements[12] * elements[7]  * elements[10];

			temp[8] =  elements[4]	 * elements[9]  * elements[15] -
						elements[4]  * elements[11] * elements[13] -
						elements[8]  * elements[5]  * elements[15] +
						elements[8]  * elements[7]  * elements[13] +
						elements[12] * elements[5]  * elements[11] -
						elements[12] * elements[7]  * elements[9];

			temp[12] = -elements[4]  * elements[9]  * elements[14] +
						elements[4]  * elements[10] * elements[13] +
						elements[8]  * elements[5]  * elements[14] -
						elements[8]  * elements[6]  * elements[13] -
						elements[12] * elements[5]  * elements[10] +
						elements[12] * elements[6]  * elements[9];

			temp[1] =  -elements[1]  * elements[10] * elements[15] +
						elements[1]  * elements[11] * elements[14] +
						elements[9]  * elements[2]  * elements[15] -
						elements[9]  * elements[3]  * elements[14] -
						elements[13] * elements[2]  * elements[11] +
						elements[13] * elements[3]  * elements[10];

			temp[5] =   elements[0]  * elements[10] * elements[15] -
						elements[0]  * elements[11] * elements[14] -
						elements[8]  * elements[2]  * elements[15] +
						elements[8]  * elements[3]  * elements[14] +
						elements[12] * elements[2]  * elements[11] -
						elements[12] * elements[3]  * elements[10];

			temp[9] =  -elements[0]  * elements[9]  * elements[15] +
						elements[0]  * elements[11] * elements[13] +
						elements[8]  * elements[1]  * elements[15] -
						elements[8]  * elements[3]  * elements[13] -
						elements[12] * elements[1]  * elements[11] +
						elements[12] * elements[3]  * elements[9];

			temp[13] =  elements[0]  * elements[9]  * elements[14] -
						elements[0]  * elements[10] * elements[13] -
						elements[8]  * elements[1]  * elements[14] +
						elements[8]  * elements[2]  * elements[13] +
						elements[12] * elements[1]  * elements[10] -
						elements[12] * elements[2]  * elements[9];

			temp[2] =   elements[1]  * elements[6]  * elements[15] -
						elements[1]  * elements[7]  * elements[14] -
						elements[5]  * elements[2]  * elements[15] +
						elements[5]  * elements[3]  * elements[14] +
						elements[13] * elements[2]  * elements[7]  -
						elements[13] * elements[3]  * elements[6];

			temp[6] =  -elements[0]  * elements[6]  * elements[15] +
						elements[0]  * elements[7]  * elements[14] +
						elements[4]  * elements[2]  * elements[15] -
						elements[4]  * elements[3]  * elements[14] -
						elements[12] * elements[2]  * elements[7]  +
						elements[12] * elements[3]  * elements[6];

			temp[10] =  elements[0]  * elements[5]  * elements[15] -
						elements[0]  * elements[7]  * elements[13] -
						elements[4]  * elements[1]  * elements[15] +
						elements[4]  * elements[3]  * elements[13] +
						elements[12] * elements[1]  * elements[7]  -
						elements[12] * elements[3]  * elements[5];

			temp[14] = -elements[0]  * elements[5]  * elements[14] +
						elements[0]  * elements[6]  * elements[13] +
						elements[4]  * elements[1]  * elements[14] -
						elements[4]  * elements[2]  * elements[13] -
						elements[12] * elements[1]  * elements[6]  +
						elements[12] * elements[2]  * elements[5];

			temp[3] =  -elements[1]  * elements[6]  * elements[11] +
						elements[1]  * elements[7]  * elements[10] +
						elements[5]  * elements[2]  * elements[11] -
						elements[5]  * elements[3]  * elements[10] -
						elements[9]  * elements[2]  * elements[7]  +
						elements[9]  * elements[3]  * elements[6];

			temp[7] =   elements[0]  * elements[6]  * elements[11] -
						elements[0]  * elements[7]  * elements[10] -
						elements[4]  * elements[2]  * elements[11] +
						elements[4]  * elements[3]  * elements[10] +
						elements[8]  * elements[2]  * elements[7]  -
						elements[8]  * elements[3]  * elements[6];

			temp[11] = -elements[0]  * elements[5]  * elements[11] +
						elements[0]  * elements[7]  * elements[9]  +
						elements[4]  * elements[1]  * elements[11] -
						elements[4]  * elements[3]  * elements[9]  -
						elements[8]  * elements[1]  * elements[7]  +
						elements[8]  * elements[3]  * elements[5];
												    
			temp[15] =  elements[0]  * elements[5]  * elements[10] -
						elements[0]  * elements[6]  * elements[9]  -
						elements[4]  * elements[1]  * elements[10] +
						elements[4]  * elements[2]  * elements[9]  +
						elements[8]  * elements[1]  * elements[6]  -
						elements[8]  * elements[2]  * elements[5];

			float determinant = elements[0] * temp[0] + elements[1] * temp[4] + elements[2] * temp[8] + elements[3] * temp[12];
			determinant = 1.0f / determinant;

			for (int i = 0; i < BFE_MATRIX_SIZE; i++)
				elements[i] = temp[i] * determinant;

			return *this;
		}

		inline const Vector3f& Matrix4::GetTranslationVector() const
		{
			return Vector3f(elements[0 + 3 * BFE_MATRIX_COLUMN_SIZE], elements[1 + 3 * BFE_MATRIX_COLUMN_SIZE], elements[2 + 3 * BFE_MATRIX_COLUMN_SIZE]);
		}

		inline const Vector3f& Matrix4::GetRotationVector() const
		{
			return Vector3f();
		}

		inline const Vector3f& Matrix4::GetScaleVector() const
		{
			return Vector3f(elements[0 + 0 * BFE_MATRIX_COLUMN_SIZE], elements[1 + 1 * BFE_MATRIX_COLUMN_SIZE], elements[2 + 2 * BFE_MATRIX_COLUMN_SIZE]);
		}

		Matrix4 Matrix4::Multiply(const Matrix4& matrixA, const Matrix4& matrixB)
		{
			Matrix4 newMatrix;

			for (unsigned int row = 0; row < BFE_MATRIX_ROW_SIZE; row++)
			{
				for (unsigned int col = 0; col < BFE_MATRIX_COLUMN_SIZE; col++)
				{
					for (unsigned int e = 0; e < BFE_MATRIX_ROW_SIZE; e++)
						newMatrix.elements[e + row * BFE_MATRIX_ROW_SIZE] += matrixA.elements[col + row * BFE_MATRIX_COLUMN_SIZE] * matrixB.elements[e + col * BFE_MATRIX_COLUMN_SIZE];
				}
			}

			return newMatrix;
		}
	}
}