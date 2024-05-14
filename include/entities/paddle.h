#pragma once

#include "entities/entity.h"

class Paddle : public Entity {
 public:
  Paddle(int x, int y, int width, int height, int speed);

  void update() override;
  void render() const override;
  inline void set_position(int x, int y);

 private:
  int m_speed;
};

inline void Paddle::set_position(int x, int y) {
  m_rect.x = x;
  m_rect.y = y;
}