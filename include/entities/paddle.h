#pragma once

#include "entities/entity.h"
#include "sdl-wrapper.h"

class Paddle : public Entity {
 public:
  Paddle();
  Paddle(SDL_Wrapper& sdl, int x, int y, int width, int height);
  void render() const override;
};