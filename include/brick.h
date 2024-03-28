#pragma once
#include <SDL2/SDL.h>
#include "window.h"

class Brick {
 public:
  Brick(int x, int y, SDL_Color color, int solidity = 1);
  ~Brick();
  void draw(const Window& window) const;

 private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_solidity;
  SDL_Color m_color;
  SDL_Rect m_rect;
};