#include "Vector2d.h"

Vector2d::Vector2d(int x1, int y1) {
	x = x1;
	y = y1;
}
Vector2d operator+(const Vector2d& a, const Vector2d& b) {
	return Vector2d(a.x + b.x, a.y + b.y);
}
Vector2d operator-(const Vector2d& a, const Vector2d& b) {
	return Vector2d(a.x - b.x, a.y - b.y);
}
Vector2d operator*(const Vector2d& a, double k) {
	return Vector2d(a.x*k, a.y*k);
}
Vector2d operator/(const Vector2d& a, double k) {
	return Vector2d(a.x / k, a.y / k);
}
