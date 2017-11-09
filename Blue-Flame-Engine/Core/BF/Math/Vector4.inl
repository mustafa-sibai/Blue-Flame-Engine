#pragma once
template<typename T>
inline Vector4<T>::Vector4() :
	x(0), y(0), z(0), w(0)
{
}

template<typename T>
inline Vector4<T>::Vector4(T value) :
	x(value), y(value), z(value), w(value)
{
}

template<typename T>
inline Vector4<T>::Vector4(T x, T y, T z, T w) :
	x(x), y(y), z(z), w(w)
{
}

template<typename T>
inline Vector4<T>::~Vector4()
{
}

template<typename T>
inline T Vector4<T>::Dot(const Vector4& vector) const
{
	return x * vector.x + y * vector.y + z * vector.z + w * vector.w;
}

template<typename T>
inline T Vector4<T>::Distance(const Vector4& vector) const
{
	Vector4 d = Direction(vector);
	return T(sqrt(d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w));
}

template<typename T>
inline T Vector4<T>::Magnitude() const
{
	return T(sqrt(Dot(*this)));
}

template<typename T>
inline Vector4<T> Vector4<T>::Direction(const Vector4& vector) const
{
	return Vector4(abs(vector.x - x), abs(vector.y - y), abs(vector.z - z), abs(vector.w - w));
}

template<typename T>
inline Vector4<T> Vector4<T>::Normalize() const
{
	T length = Magnitude();

	if (length > 0)
		return Vector4(x / length, y / length, z / length, w / length);
	else
		return Vector4(0);
}

template<typename T>
inline Vector4<T> Vector4<T>::Center() const
{
	return Vector4(x / 2, y / 2, z / 2, w / 2);
}

template<typename T>
inline Vector4<T> Vector4<T>::Min()
{
	T min = Math::Min(x, y);
	T min2 = Math::Min(z, w);
	return Vector4(Math::Min(min, min2));
}

template<typename T>
inline Vector4<T> Vector4<T>::Max()
{
	T max = Math::Max(x, y);
	T max2 = Math::Max(z, w);
	return Vector4(Math::Max(max, max2));
}

template<typename T>
inline Vector4<T>& Vector4<T>::operator+=(const Vector4& right)
{
	x += right.x;
	y += right.y;
	z += right.z;
	w += right.w;
	return *this;
}

template<typename T>
inline Vector4<T>& Vector4<T>::operator-=(const Vector4& right)
{
	x -= right.x;
	y -= right.y;
	z -= right.z;
	w -= right.w;
	return *this;
}

template<typename T>
inline Vector4<T>& Vector4<T>::operator*=(const Vector4& right)
{
	x *= right.x;
	y *= right.y;
	z *= right.z;
	w *= right.w;
	return *this;
}

template<typename T>
inline Vector4<T>& Vector4<T>::operator/=(const Vector4& right)
{
	x /= right.x;
	y /= right.y;
	z /= right.z;
	w /= right.w;
	return *this;
}

template<typename T>
inline bool Vector4<T>::operator>(const Vector4& right)
{
	return Magnitude() > right.Magnitude();
}

template<typename T>
inline bool Vector4<T>::operator>=(const Vector4& right)
{
	return Magnitude() >= right.Magnitude();
}

template<typename T>
inline bool Vector4<T>::operator<(const Vector4& right)
{
	return Magnitude() < right.Magnitude();
}

template<typename T>
inline bool Vector4<T>::operator<=(const Vector4& right)
{
	return Magnitude() <= right.Magnitude();
}

template<typename T>
inline bool Vector4<T>::operator==(const Vector4& right)
{
	return x == right.x && y == right.y && z == right.z && w == right.w;
}

template<typename T>
inline bool Vector4<T>::operator!=(const Vector4& right)
{
	return !(*this == right);
}