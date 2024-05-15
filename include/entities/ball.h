/**
 * @file ball.h
 * @brief Déclaration de la classe Ball, qui représente une balle dans le jeu.
 */

#pragma once

#include "entities/brick.h"
#include "entities/entity.h"
#include "entities/paddle.h"
#include "vector2D.h"

/**
 * @class Ball
 * @brief Représente une balle dans le jeu Breakout.
 * 
 * La classe Ball hérite de la classe Entity et gère le mouvement, les collisions et le rendu de la balle.
 */
class Ball : public Entity {
 public:
  /**
   * @brief Constructeur de la classe Ball.
   * 
   * @param x La position x de la balle.
   * @param y La position y de la balle.
   * @param width La largeur de la balle.
   * @param height La hauteur de la balle.
   * @param texture La texture de la balle.
   * @param direction La direction initiale de la balle.
   * @param speed La vitesse initiale de la balle.
   */
  Ball(int x, int y, int width, int height, SDL_Texture_ptr& texture,
       const Vector2D<double>& direction, float speed);

  /**
   * @brief Met à jour la position et l'état de la balle.
   */
  void update() override;

  /**
   * @brief Rend la balle à l'écran.
   */
  void render() const override;

  /**
   * @brief Obtient la direction actuelle de la balle.
   * @return La direction actuelle de la balle sous forme de Vector2D<double>.
   */
  inline Vector2D<double> get_direction() const;

  /**
   * @brief Définit la direction de la balle.
   * @param x La composante x de la direction.
   * @param y La composante y de la direction.
   */
  inline void set_direction(double x, double y);

  /**
   * @brief Obtient la vitesse actuelle de la balle.
   * @return La vitesse actuelle de la balle.
   */
  inline float get_speed() const;

  /**
   * @brief Définit la vitesse de la balle.
   * @param speed La nouvelle vitesse de la balle.
   */
  inline void set_speed(float speed);

  /**
   * @brief Vérifie la collision avec la paddle.
   * @param paddle La paddle à vérifier pour la collision.
   */
  void check_collision(const Paddle& paddle);

  /**
   * @brief Vérifie la collision avec une brique.
   * @param brick La brique à vérifier pour la collision.
   * @param score Référence vers le score pour mise à jour en cas de collision.
   */
  void check_collision(Brick& brick, int& score);

  /**
   * @brief Gère le rebondissement de la balle après une collision.
   */
  void bounce();

 private:
  Vector2D<double> m_direction; /**< La direction actuelle de la balle. */
  float m_speed;                /**< La vitesse actuelle de la balle. */
  bool
      m_is_colliding; /**< Indique si la balle est en collision avec la paddle. */
  float
      m_collision_cooldown; /**< Délai pour éviter les doubles collisions avec les briques. */
};

inline Vector2D<double> Ball::get_direction() const {
  return m_direction;
}

inline void Ball::set_direction(double x, double y) {
  m_direction.x = x;
  m_direction.y = y;
}

inline float Ball::get_speed() const {
  return m_speed;
}

inline void Ball::set_speed(float speed) {
  m_speed = speed;
}
