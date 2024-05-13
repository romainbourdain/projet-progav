#pragma once

#include "entities/entity.h"

enum class BrickShape { RECTANGLE, TRIANGLE, HEXAGON };

class Brick : public Entity {
 private:
  int m_health;
  BrickShape m_shape;

 public:
  Brick(SDL_Wrapper& sdl, int x, int y, int width, int height, int health);
  void render() const override;
};