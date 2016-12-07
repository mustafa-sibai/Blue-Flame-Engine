#pragma once
#include <iostream>
#include <math.h>

struct Vector4
{
	float x, y, z, w;

	Vector4();
	Vector4(float value);
	Vector4(float x, float y, float z, float w);
	~Vector4();

	float Dot(const Vector4& vector) const;
	float Magnitude() const;
	Vector4 Normalize() const;

	friend Vector4 operator+(const Vector4& left, const Vector4& right);
	friend Vector4 operator-(const Vector4& left, const Vector4& right);
	friend Vector4 operator*(const Vector4& left, const Vector4& right);
	friend Vector4 operator/(const Vector4& left, const Vector4& right);

	Vector4& operator+=(const Vector4& right);
	Vector4& operator-=(const Vector4& right);
	Vector4& operator*=(const Vector4& right);
	Vector4& operator/=(const Vector4& right);

	friend std::ostream& operator<<(std::ostream& os, const Vector4& vector);
};