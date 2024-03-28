#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class Brick {
 public:
  Brick(const int x, const int y, const SDL_Color color,
        const int solidity = 1);
  ~Brick();
  void draw(const Window& window) const;
  SDL_Rect get_rect() const;

 private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_solidity;
  SDL_Color m_color;
  SDL_Rect m_rect;
};