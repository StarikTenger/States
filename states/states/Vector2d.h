#pragma once
class Vector2d {
public:
	int x=0, y=0;
	Vector2d() {};
	Vector2d(int x1, int y1);
};

Vector2d operator+(const Vector2d& a, const Vector2d& b);
Vector2d operator-(const Vector2d& a, const Vector2d& b);
Vector2d operator*(const Vector2d& a, double k);
Vector2d operator/(const Vector2d& a, double k);