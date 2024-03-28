#include <SDL2/SDL.h>
#include <iostream>

#include "lib/const.h"
#include "lib/utils.h"

#include "brick.h"

Brick::Brick(const int x, const int y, const SDL_Color color,
             const int solidity)
    : m_x(x),
      m_y(y),
      m_width(Constants::BRICK_WIDTH),
      m_height(Constants::BRICK_HEIGHT),
      m_color(color),
      m_solidity(solidity) {
  m_rect = {m_x, m_y, m_width, m_height};
}

Brick::~Brick() {}

void Brick::draw(const Window& window) const {
  window.draw_rect(m_rect, Constants::BRICK_BORDER);
  window.draw_rect(
      {m_x + Constants::BRICK_BORDER_WIDTH, m_y + Constants::BRICK_BORDER_WIDTH,
       m_width - Constants::BRICK_BORDER_WIDTH * 2,
       m_height - Constants::BRICK_BORDER_WIDTH * 2},
      m_color);
}

SDL_Rect Brick::get_rect() const {
  return m_rect;
}