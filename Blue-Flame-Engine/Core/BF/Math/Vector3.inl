#pragma once
template<typename T>
inline Vector3<T>::Vector3() :
	x(0), y(0), z(0)
{
}

template<typename T>
inline Vector3<T>::Vector3(T value) :
	x(value), y(value), z(value)
{
}

template<typename T>
inline Vector3<T>::Vector3(T x, T y, T z) :
	x(x), y(y), z(z)
{
}

template<typename T>
inline Vector3<T>::~Vector3()
{
}

template<typename T>
inline T Vector3<T>::Dot(const Vector3& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

template<typename T>
inline T Vector3<T>::Distance(const Vector3& vector) const
{
	Vector3 d = Direction(vector);
	return T(sqrt(d.x * d.x + d.y * d.y + d.z * d.z));
}

template<typename T>
inline T Vector3<T>::Magnitude() const
{
	return T(sqrt(Dot(*this)));
}

template<typename T>
inline Vector3<T> Vector3<T>::Cross(const Vector3& vector) const
{
	return Vector3(y * vector.z - z * vector.y, z * vector.x - x * vector.z, x * vector.y - y * vector.x);
}

template<typename T>
inline Vector3<T> Vector3<T>::Direction(const Vector3& vector) const
{
	return Vector3(abs(vector.x - x), abs(vector.y - y), abs(vector.z - z));
}

template<typename T>
inline Vector3<T> Vector3<T>::Normalize() const
{
	T length = Magnitude();

	if (length > 0)
		return Vector3(x / length, y / length, z / length);
	else
		return Vector3(0);
}

template<typename T>
inline Vector3<T> Vector3<T>::Center() const
{
	return Vector3(x / 2, y / 2, z / 2);
}

template<typename T>
inline Vector3<T> Vector3<T>::Min()
{
	T min = Math::Min(x, y);
	return Vector3(Math::Min(min, z));
}

template<typename T>
inline Vector3<T> Vector3<T>::Max()
{
	T max = Math::Max(x, y);
	return Vector3(Math::Max(max, z));
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator+=(const Vector3& right)
{
	x += right.x;
	y += right.y;
	z += right.z;
	return *this;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator-=(const Vector3& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;
	return *this;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator*=(const Vector3& right)
{
	x *= right.x;
	y *= right.y;
	z *= right.z;
	return *this;
}

template<typename T>
inline Vector3<T>& Vector3<T>::operator/=(const Vector3& right)
{
	x /= right.x;
	y /= right.y;
	z /= right.z;
	return *this;
}

template<typename T>
inline bool Vector3<T>::operator>(const Vector3& right)
{
	return Magnitude() > right.Magnitude();
}

template<typename T>
inline bool Vector3<T>::operator>=(const Vector3& right)
{
	return Magnitude() >= right.Magnitude();
}

template<typename T>
inline bool Vector3<T>::operator<(const Vector3& right)
{
	return Magnitude() < right.Magnitude();
}

template<typename T>
inline bool Vector3<T>::operator<=(const Vector3& right)
{
	return Magnitude() <= right.Magnitude();
}

template<typename T>
inline bool Vector3<T>::operator==(const Vector3& right)
{
	return x == right.x && y == right.y && z == right.z;
}

template<typename T>
inline bool Vector3<T>::operator!=(const Vector3& right)
{
	return !(*this == right);
}