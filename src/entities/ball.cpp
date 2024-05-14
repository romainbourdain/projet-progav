#include "entities/ball.h"
#include "config.h"

Ball::Ball(int x, int y, int width, int height,
           const Vector2D<float>& direction, float speed)
    : Entity(x, y, width, height), m_direction(direction), m_speed(speed) {}

void Ball::update() {
  Vector2D velocity = m_direction * m_speed;
  m_rect.x += velocity.x;
  m_rect.y += velocity.y;
}

void Ball::render() const {
  SDL_Wrapper::draw_rect(m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                         Config::BALL_COLOR);
}
