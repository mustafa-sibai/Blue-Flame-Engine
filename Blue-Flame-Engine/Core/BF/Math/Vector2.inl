template<typename T>
inline Vector2<T>::Vector2() :
	x(0), y(0)
{
}

template<typename T>
inline Vector2<T>::Vector2(T value) :
	x(value), y(value)
{
}

template<typename T>
inline Vector2<T>::Vector2(T x, T y) :
	x(x), y(y)
{
}

template<typename T>
inline Vector2<T>::~Vector2()
{
}

template<typename T>
inline T Vector2<T>::Dot(const Vector2& vector) const
{
	return x * vector.x + y * vector.y;
}

template<typename T>
inline T Vector2<T>::Distance(const Vector2& vector) const
{
	Vector2 d = Direction(vector);
	return T(sqrt(d.x * d.x + d.y * d.y));
}

template<typename T>
inline T Vector2<T>::Magnitude() const
{
	return T(sqrt(Dot(*this)));
}

template<typename T>
inline Vector2<T> Vector2<T>::Direction(const Vector2& vector) const
{
	return Vector2(abs(vector.x - x), abs(vector.y - y));
}

template<typename T>
inline Vector2<T> Vector2<T>::Normalize() const
{
	T length = Magnitude();

	if (length > 0)
		return Vector2(x / length, y / length);
	else
		return Vector2(0);
}

template<typename T>
inline Vector2<T> Vector2<T>::Center() const
{
	return Vector2(x / 2, y / 2);
}

template<typename T>
inline Vector2<T> Vector2<T>::Min()
{
	return Vector2(Math::Min(x, y));
}

template<typename T>
inline Vector2<T> Vector2<T>::Max()
{
	return Vector2(Math::Max(x, y));
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator+=(const Vector2& right)
{
	x += right.x;
	y += right.y;
	return *this;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator-=(const Vector2& right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator*=(const Vector2& right)
{
	x *= right.x;
	y *= right.y;
	return *this;
}

template<typename T>
inline Vector2<T>& Vector2<T>::operator/=(const Vector2& right)
{
	x /= right.x;
	y /= right.y;
	return *this;
}

template<typename T>
inline bool Vector2<T>::operator>(const Vector2& right)
{
	return Magnitude() > right.Magnitude();
}

template<typename T>
inline bool Vector2<T>::operator>=(const Vector2& right)
{
	return Magnitude() >= right.Magnitude();
}

template<typename T>
inline bool Vector2<T>::operator<(const Vector2& right)
{
	return Magnitude() < right.Magnitude();
}

template<typename T>
inline bool Vector2<T>::operator<=(const Vector2& right)
{
	return Magnitude() <= right.Magnitude();
}

template<typename T>
inline bool Vector2<T>::operator==(const Vector2& right)
{
	return x == right.x && y == right.y;
}

template<typename T>
inline bool Vector2<T>::operator!=(const Vector2& right)
{
	return !(*this == right);
}