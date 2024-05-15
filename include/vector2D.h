/**
 * @file vector2D.h
 * @brief Déclaration de la classe template Vector2D, qui représente un vecteur 2D.
 */

#pragma once

#include <cmath>

/**
 * @class Vector2D
 * @brief Représente un vecteur 2D.
 * 
 * La classe template Vector2D fournit des opérations vectorielles courantes telles que l'addition, la soustraction, la normalisation, etc.
 * 
 * @tparam T Type des composants du vecteur (par exemple, int, float, double).
 */
template <typename T>
class Vector2D {
 public:
  T x; /**< Composante x du vecteur. */
  T y; /**< Composante y du vecteur. */

  /**
   * @brief Constructeur de la classe Vector2D.
   * 
   * @param x La composante x du vecteur.
   * @param y La composante y du vecteur.
   */
  Vector2D(T x, T y) : x(x), y(y) {}

  /**
   * @brief Calcule la magnitude (longueur) du vecteur.
   * 
   * @return La magnitude du vecteur.
   */
  float magnitude() const { return sqrt(x * x + y * y); }

  /**
   * @brief Normalise le vecteur (le rend de longueur 1).
   * 
   * @return Un nouveau vecteur normalisé.
   */
  Vector2D<T> normalize() const {
    float mag = magnitude();
    return Vector2D<T>(x / mag, y / mag);
  }

  /**
   * @brief Additionne deux vecteurs.
   * 
   * @param other Le vecteur à ajouter.
   * @return Un nouveau vecteur résultant de l'addition.
   */
  Vector2D<T> operator+(const Vector2D<T>& other) const {
    return Vector2D<T>(x + other.x, y + other.y);
  }

  /**
   * @brief Soustrait deux vecteurs.
   * 
   * @param other Le vecteur à soustraire.
   * @return Un nouveau vecteur résultant de la soustraction.
   */
  Vector2D<T> operator-(const Vector2D<T>& other) const {
    return Vector2D<T>(x - other.x, y - other.y);
  }

  /**
   * @brief Multiplie le vecteur par un scalaire.
   * 
   * @param scalar Le scalaire par lequel multiplier.
   * @return Un nouveau vecteur résultant de la multiplication.
   */
  Vector2D<T> operator*(T scalar) const {
    return Vector2D<T>(x * scalar, y * scalar);
  }

  /**
   * @brief Divise le vecteur par un scalaire.
   * 
   * @param scalar Le scalaire par lequel diviser.
   * @return Un nouveau vecteur résultant de la division.
   */
  Vector2D<T> operator/(T scalar) const {
    return Vector2D<T>(x / scalar, y / scalar);
  }

  /**
   * @brief Additionne un vecteur à ce vecteur.
   * 
   * @param other Le vecteur à ajouter.
   */
  void operator+=(const Vector2D<T>& other) {
    x += other.x;
    y += other.y;
  }

  /**
   * @brief Soustrait un vecteur à ce vecteur.
   * 
   * @param other Le vecteur à soustraire.
   */
  void operator-=(const Vector2D<T>& other) {
    x -= other.x;
    y -= other.y;
  }

  /**
   * @brief Multiplie ce vecteur par un scalaire.
   * 
   * @param scalar Le scalaire par lequel multiplier.
   */
  void operator*=(T scalar) {
    x *= scalar;
    y *= scalar;
  }

  /**
   * @brief Multiplie ce vecteur par un autre vecteur.
   * 
   * @param other Le vecteur par lequel multiplier.
   */
  void operator*=(const Vector2D<T>& other) {
    x *= other.x;
    y *= other.y;
  }

  /**
   * @brief Divise ce vecteur par un scalaire.
   * 
   * @param scalar Le scalaire par lequel diviser.
   */
  void operator/=(T scalar) {
    x /= scalar;
    y /= scalar;
  }
};
