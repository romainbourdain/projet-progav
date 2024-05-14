#pragma once

template <typename T>
class Vector2D {
 public:
  T x;
  T y;

  Vector2D(T x, T y) : x(x), y(y) {}

  float magnitude() const { return sqrt(x * x + y * y); }

  Vector2D<T> normalize() const {
    float mag = magnitude();
    return Vector2D<T>(x / mag, y / mag);
  }

  Vector2D<T> operator+(const Vector2D<T>& other) const {
    return Vector2D<T>(x + other.x, y + other.y);
  }

  Vector2D<T> operator-(const Vector2D<T>& other) const {
    return Vector2D<T>(x - other.x, y - other.y);
  }

  Vector2D<T> operator*(T scalar) const {
    return Vector2D<T>(x * scalar, y * scalar);
  }

  Vector2D<T> operator/(T scalar) const {
    return Vector2D<T>(x / scalar, y / scalar);
  }

  void operator+=(const Vector2D<T>& other) {
    x += other.x;
    y += other.y;
  }

  void operator-=(const Vector2D<T>& other) {
    x -= other.x;
    y -= other.y;
  }

  void operator*=(T scalar) {
    x *= scalar;
    y *= scalar;
  }

  void operator*=(const Vector2D<T>& other) {
    x *= other.x;
    y *= other.y;
  }

  void operator/=(T scalar) {
    x /= scalar;
    y /= scalar;
  }
};