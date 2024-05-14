#include "game-manager.h"
#include "config.h"

GameManager::GameManager() : m_score(0), m_lives(3), m_is_playing(true) {
  m_paddle = std::make_unique<Paddle>(
      Config::WINDOW_WIDTH / 2, 500, Config::PADDLE_WIDTH,
      Config::PADDLE_HEIGHT, Config::PADDLE_SPEED);
  m_balls.push_back(std::make_unique<Ball>(
      Config::WINDOW_WIDTH / 2, 400, Config::BALL_RADIUS, Config::BALL_RADIUS,
      Vector2D<float>(1, 1).normalize(), Config::BALL_SPEED));
  load_level();
}

void GameManager::update() {
  if (!m_is_playing)
    return;

  for (auto& ball : m_balls) {
    ball->update();
  }
  m_paddle->update();
  check_collisions();
}

void GameManager::check_collisions() {
  for (auto& ball : m_balls) {
    SDL_Rect ball_rect = ball->get_rect();
    SDL_Rect paddle_rect = m_paddle->get_rect();

    if (SDL_HasIntersection(&ball_rect, &paddle_rect)) {
      // intersection with paddle
    }

    for (auto& brick : m_bricks) {
      SDL_Rect brick_rect = brick->get_rect();
      if (!brick->is_destroyed() &&
          SDL_HasIntersection(&ball_rect, &brick_rect)) {
        brick->destroy();
        m_score += 10;
        // change ball direction
      }
    }

    if (ball_rect.x < 0 || ball_rect.x + ball_rect.w > Config::WINDOW_WIDTH) {
      ball->set_direction(-ball->get_direction().x, ball->get_direction().y);
    }

    if (ball_rect.y < 0) {
      ball->set_direction(ball->get_direction().x, -ball->get_direction().y);
    }

    if (ball_rect.y + ball_rect.h > Config::WINDOW_HEIGHT) {
      m_lives--;
      ball->set_direction(ball->get_direction().x, -ball->get_direction().y);
      if (m_lives <= 0) {
        // game over
        m_is_playing = false;
      }
    }
  }
}

void GameManager::load_level() {
  for (int y = 0; y < 3; y++) {
    for (int x = 0; x < 10; x++) {
      m_bricks.push_back(std::make_unique<Brick>(
          x * Config::BRICK_WIDTH, y * Config::BRICK_HEIGHT,
          Config::BRICK_WIDTH, Config::BRICK_HEIGHT));
    }
  }
}