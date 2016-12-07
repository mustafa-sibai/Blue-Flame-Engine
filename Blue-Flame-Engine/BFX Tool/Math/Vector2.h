#pragma once
#include <iostream>
#include <math.h>

struct Vector2
{
	float x, y;

	Vector2();
	Vector2(float value);
	Vector2(float x, float y);
	~Vector2();

	float Dot(const Vector2& vector) const;
	float Magnitude() const;
	Vector2 Normalize() const;

	friend Vector2 operator+(const Vector2& left, const Vector2& right);
	friend Vector2 operator-(const Vector2& left, const Vector2& right);
	friend Vector2 operator*(const Vector2& left, const Vector2& right);
	friend Vector2 operator/(const Vector2& left, const Vector2& right);

	Vector2& operator+=(const Vector2& right);
	Vector2& operator-=(const Vector2& right);
	Vector2& operator*=(const Vector2& right);
	Vector2& operator/=(const Vector2& right);

	friend std::ostream& operator<<(std::ostream& os, const Vector2& vector);
};