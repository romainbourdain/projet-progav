#include <SDL2/SDL.h>
#include <iostream>

#include "brick.h"
#include "const.h"
#include "utils.h"

Brick::Brick(int x, int y, int solidity)
    : m_x(x),
      m_y(y),
      m_width(BRICK_WIDTH),
      m_height(BRICK_HEIGHT),
      m_solidity(solidity) {
  m_rect = {m_x, m_y, m_width, m_height};
}

Brick::~Brick() {}

void Brick::draw(const Window& window) const {
  window.draw_rect(m_rect, RED);
}