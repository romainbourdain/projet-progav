#include "game-object/brick.h"

#include "sdl-wrapper.h"

Brick::Brick(SDL_Wrapper& sdl, int x, int y, int width, int height, int health)
    : GameObject(sdl, x, y, width, height), m_health(health) {}

void Brick::render() const {
  m_sdl.drawRect(m_x, m_y, m_width, m_height, {255, 255, 255, 255});
}