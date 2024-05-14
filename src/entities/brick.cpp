#include "entities/brick.h"
#include "config.h"

Brick::Brick(int x, int y, int width, int height)
    : Entity(x, y, width, height), m_destroyed(false) {}

void Brick::update() {}

void Brick::render() const {

  SDL_Wrapper::draw_rect(m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                         Config::BRICK_COLOR);
  SDL_Wrapper::draw_rect(m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                         Config::BRICK_BORDER_COLOR, false);
}