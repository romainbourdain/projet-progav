#pragma once

#include "entities/entity.h"

class Ball : public Entity {
 private:
  int m_speed;
  int m_dx;
  int m_dy;

 public:
  Ball();
  Ball(SDL_Wrapper& sdl, int x, int y, int width, int height);
  void render() const override;
};