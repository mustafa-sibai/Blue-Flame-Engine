#pragma once
#include <iostream>
#include <math.h>

struct Vector3
{
	float x, y, z;

	Vector3();
	Vector3(float value);
	Vector3(float x, float y, float z);
	~Vector3();

	float Dot(const Vector3& vector) const;
	Vector3 Vector3::Cross(const Vector3& vector) const;
	float Magnitude() const;
	Vector3 Normalize() const;

	friend Vector3 operator+(const Vector3& left, const Vector3& right);
	friend Vector3 operator-(const Vector3& left, const Vector3& right);
	friend Vector3 operator*(const Vector3& left, const Vector3& right);
	friend Vector3 operator/(const Vector3& left, const Vector3& right);

	Vector3& operator+=(const Vector3& right);
	Vector3& operator-=(const Vector3& right);
	Vector3& operator*=(const Vector3& right);
	Vector3& operator/=(const Vector3& right);

	friend std::ostream& operator<<(std::ostream& os, const Vector3& vector);
};