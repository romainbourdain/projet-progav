#include "entities/ball.h"
#include "config.h"
#include "entities/brick.h"

#include <cmath>

Ball::Ball(int x, int y, int width, int height, SDL_Texture_ptr& texture,
           const Vector2D<double>& direction, float speed)
    : Entity(x, y, width, height, texture),
      m_direction(direction),
      m_speed(speed),
      m_is_colliding(false),
      m_collision_cooldown(0.0f) {}

void Ball::update() {
  Vector2D velocity = m_direction * m_speed;
  m_rect.x += velocity.x;
  m_rect.y += velocity.y;

  if (m_collision_cooldown > 0.0f)
    m_collision_cooldown -= 1.0f / Config::FRAMES_PER_SECOND;
}

void Ball::render() const {
  SDL_Wrapper::render_texture(m_texture, m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                              SDL_Wrapper::Origin::TOP_LEFT);
}

void Ball::check_collision(const Paddle& paddle) {
  SDL_Rect paddle_rect = paddle.get_rect();

  if (m_rect.y + m_rect.h < paddle_rect.y)
    m_is_colliding = false;

  if (m_is_colliding || m_direction.y < 0)
    return;

  if (SDL_HasIntersection(&m_rect, &paddle_rect)) {
    m_is_colliding = true;

    double paddle_center = paddle_rect.x + paddle_rect.w / 2;
    double ball_center = m_rect.x + m_rect.w / 2;
    double reflection_angle = 2 * (ball_center - paddle_center) /
                              (paddle_rect.w + m_rect.w) *
                              Config::MAX_BOUNCE_ANGLE;
    m_direction = Vector2D<double>(std::sin(M_PI - reflection_angle),
                                   std::cos(M_PI - reflection_angle));
  }
}

void Ball::check_collision(Brick& brick, int& score) {
  if (brick.is_destroyed())
    return;

  SDL_Rect brick_rect = brick.get_rect();
  if (SDL_HasIntersection(&m_rect, &brick_rect) &&
      m_collision_cooldown <= 0.0f) {
    m_collision_cooldown = Config::COLLISION_COOLDOWN;

    brick.destroy();
    score += Config::BRICK_SCORE;

    float ball_center_x = m_rect.x + m_rect.w / 2;
    float ball_center_y = m_rect.y + m_rect.h / 2;

    if (ball_center_x > brick_rect.x &&
        ball_center_x < brick_rect.x + brick_rect.w) {
      m_direction *= Vector2D<double>(1, -1);
    } else if (ball_center_y > brick_rect.y &&
               ball_center_y < brick_rect.y + brick_rect.h) {
      m_direction *= Vector2D<double>(-1, 1);
    } else {
      m_direction *= Vector2D<double>(-1, -1);
    }
  }
}

void Ball::bounce() {
  if (m_rect.x < 0 || m_rect.x + m_rect.w > Config::WINDOW_WIDTH) {
    m_direction *= Vector2D<double>(-1, 1);
  }

  if (m_rect.y < 0 || m_rect.y + m_rect.h > Config::WINDOW_HEIGHT) {
    m_direction *= Vector2D<double>(1, -1);
  }
}