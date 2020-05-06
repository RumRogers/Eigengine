#pragma once
#include <cmath>

namespace EigenMath
{
	class Vector2D
	{
	public:
		float x, y;
	public:
		explicit Vector2D(float x = 0, float y = 0) : x(x), y(y) {};
		Vector2D(const Vector2D& rhs) { x = rhs.x; y = rhs.y; }

		Vector2D& operator=(const Vector2D& rhs) { x = rhs.x; y = rhs.y; return *this; }
		inline float& operator[](const int idx) { return *(&x + idx); }
		inline const float& operator[](const int idx) const { return *(&x + idx); }
		inline Vector2D& operator+=(const Vector2D& rhs) { x += rhs.x; y += rhs.y; return *this; }
		inline Vector2D& operator-=(const Vector2D& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
		inline Vector2D& operator*=(const float scalar) { x *= scalar; y *= scalar; return *this; }
		inline Vector2D& operator/=(const float scalar) { x /= scalar; y /= scalar; return *this; }
		inline Vector2D operator+(const Vector2D& rhs) const { return Vector2D(*this) += rhs; }
		inline Vector2D operator-(const Vector2D& rhs) const { return Vector2D(*this) -= rhs; }
		inline Vector2D operator*(const float scalar) const { return Vector2D(*this) *= scalar; }
		inline Vector2D operator/(const float scalar) const { return Vector2D(*this) /= scalar; }
		inline Vector2D operator-() const { return Vector2D(*this) *= -1; }

		inline float magnitude() const { return std::sqrtf(x * x + y * y); }
		inline float length() const { return magnitude(); }
		inline Vector2D& normalize() { return *this /= magnitude(); }
		inline Vector2D normalized() const { return Vector2D(*this).normalize(); }		
		inline float dot(const Vector2D& rhs) const { return x * rhs.x + y * rhs.y; }
	};
}


