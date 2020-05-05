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
		float& operator[](const int idx) { return *(&x + idx); }
		const float& operator[](const int idx) const { return *(&x + idx); }
		Vector2D operator+(const Vector2D& rhs) const { return Vector2D(x + rhs.x, y + rhs.y); }
		Vector2D operator-(const Vector2D& rhs) const { return Vector2D(x - rhs.x, y - rhs.y); }
		Vector2D operator*(const float scalar) const { return Vector2D(x * scalar, y * scalar); }
		Vector2D operator/(const float scalar) const { return Vector2D(x / scalar, y / scalar); }
		Vector2D& operator+=(const Vector2D& rhs) { x += rhs.x; y += rhs.y; return *this; }
		Vector2D& operator-=(const Vector2D& rhs) { x -= rhs.x; y -= rhs.y; return *this; }
		Vector2D& operator*=(const float scalar) { x *= scalar; y *= scalar; return *this; }
		Vector2D& operator/=(const float scalar) { x /= scalar; y /= scalar; return *this; }
		
		inline float magnitude() const { return std::sqrtf(x * x + y * y); }
		inline float length() const { return magnitude(); }
		inline Vector2D& normalize() { return *this /= magnitude(); }
		inline Vector2D normalized() const { return Vector2D(*this).normalize(); }		
		inline float dot(const Vector2D& rhs) { return x * rhs.x + y * rhs.y; }
	};
}


