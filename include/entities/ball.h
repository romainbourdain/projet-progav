#pragma once

#include "entities/entity.h"
#include "vector2D.h"

class Ball : public Entity {
 public:
  Ball(int x, int y, int width, int height, const Vector2D<float>& direction,
       float speed);

  void update() override;
  void render() const override;

  inline Vector2D<float> get_direction() const;
  inline void set_direction(float x, float y);
  inline float get_speed() const;
  inline void set_speed(float speed);

 private:
  Vector2D<float> m_direction;
  float m_speed;
};

inline Vector2D<float> Ball::get_direction() const {
  return m_direction;
}

inline void Ball::set_direction(float x, float y) {
  m_direction.x = x;
  m_direction.y = y;
}

inline float Ball::get_speed() const {
  return m_speed;
}

inline void Ball::set_speed(float speed) {
  m_speed = speed;
}