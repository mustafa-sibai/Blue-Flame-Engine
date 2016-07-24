#pragma once
#include "Vector3.h"
#include "../Graphics/Renderer/Renderer.h"

#ifdef COMPILE_BLUE_FLAME_ENGINE   
	#define DLLEXPORT __declspec(dllexport) 
#else   
	#define DLLEXPORT __declspec(dllimport) 
#endif

namespace BFE
{
	namespace Math
	{
		class DLLEXPORT Matrix4
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

				friend const Matrix4 operator*(const Matrix4 &LeftMatrix, const Matrix4 &RightMatrix) { return Matrix4::Multiplay(LeftMatrix, RightMatrix); }

			private:
				static Matrix4 Multiplay(const Matrix4 &LeftMatrix, const Matrix4 &RightMatrix);
		};
	}
}