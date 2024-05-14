#include "entities/paddle.h"
#include "config.h"
#include "sdl-wrapper.h"

Paddle::Paddle(int x, int y, int width, int height, int speed)
    : Entity(x, y, width, height), m_speed(speed) {}

void Paddle::update() {
  if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_LEFT) && m_rect.x > 0) {
    m_rect.x -= m_speed;
  }
  if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_RIGHT) &&
      m_rect.x + m_rect.w < Config::WINDOW_WIDTH) {
    m_rect.x += m_speed;
  }
}

void Paddle::render() const {
  SDL_Wrapper::draw_rect(m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                         Config::PADDLE_COLOR);
}