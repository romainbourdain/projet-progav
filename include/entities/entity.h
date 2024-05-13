#pragma once

#include "sdl-wrapper.h"

class Entity {
 protected:
  SDL_Wrapper& m_sdl;
  int m_x;
  int m_y;
  int m_width;
  int m_height;

 public:
  Entity(SDL_Wrapper& sdl, int x, int y, int width, int height)
      : m_sdl(sdl), m_x(x), m_y(y), m_width(width), m_height(height){};
  virtual void render() const = 0;
};