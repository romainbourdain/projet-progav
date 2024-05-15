#pragma once

#include "entities/brick.h"
#include "entities/entity.h"
#include "entities/paddle.h"

#include "vector2D.h"

class Ball : public Entity {
 public:
  Ball(int x, int y, int width, int height, SDL_Texture_ptr& texture,
       const Vector2D<double>& direction, float speed);

  void update() override;
  void render() const override;

  inline Vector2D<double> get_direction() const;
  inline void set_direction(double x, double y);
  inline float get_speed() const;
  inline void set_speed(float speed);

  void check_collision(const Paddle& paddle);
  void check_collision(Brick& brick, int& score);
  void bounce();

 private:
  Vector2D<double> m_direction;
  float m_speed;
  bool m_is_colliding;         // éviter les doubles collisions avec paddle
  float m_collision_cooldown;  // éviter la double collision avec brick
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