#pragma once

#include "Vector2D.h"

namespace EigenMath
{
	static const float PI = 3.14159265358979323846f;
	static const float degToRad = 0.0174533f;
	static const float radToDeg = 57.2958f;

	class Transform2D
	{
	public:
		Vector2D position;
		Vector2D scale;
		float rotation;

		explicit Transform2D(const float xPos = 0, const float yPos = 0, const float rotation = 0) : position{xPos, yPos}, rotation(rotation) {}
		explicit Transform2D(const Vector2D& position, const float rotation = 0) : Transform2D(position.x, position.y, rotation) {}
		inline void translate(const float x, const float y) { translate(Vector2D(x, y)); };
		inline void translate(const Vector2D& vec) { position += vec; };
		inline void rotate(const float rads) { rotation += rads; };
		inline void rotateDegs(const float degs) { rotation += degToRad * degs; };
		inline void setScale(const float x, const float y) { setScale(Vector2D(x, y)); };
		inline void setScale(const Vector2D& vec) { scale = vec; };
		inline void setRotation(const float rads) { rotation = rads; };
		inline void setRotationDegs(const float degs) { rotation = degToRad * degs; }
		inline Vector2D getForwardDirection() const { return Vector2D(std::cosf(position.x), std::sinf(position.y)); }
		inline Vector2D getUpwardsDirection() const { return Vector2D(-std::sinf(position.y), std::cosf(position.x)); }
	};
}