#include "game-manager.h"
#include "config.h"

GameManager::GameManager()
    : m_paddle_texture(SDL_Wrapper::load_texture("assets/images/paddle.png")),
      m_ball_texture(SDL_Wrapper::load_texture("assets/images/ball.png")),
      m_brick_textures(
          {SDL_Wrapper::load_texture("assets/images/brick-1.png"),
           SDL_Wrapper::load_texture("assets/images/brick-2.png"),
           SDL_Wrapper::load_texture("assets/images/brick-3.png"),
           SDL_Wrapper::load_texture("assets/images/brick-4.png"),
           SDL_Wrapper::load_texture("assets/images/brick-5.png")}),

      m_paddle(Config::WINDOW_WIDTH / 2, Config::PADDLE_Y, Config::PADDLE_WIDTH,
               Config::PADDLE_HEIGHT, m_paddle_texture, Config::PADDLE_SPEED),
      m_score(0),
      m_lives(Config::LIFE_COUNT),
      m_is_playing(true) {
  m_balls.push_back(Ball(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2,
                         Config::BALL_RADIUS, Config::BALL_RADIUS,
                         m_ball_texture, Vector2D<double>(1, -1).normalize(),
                         Config::BALL_SPEED));
  load_level();
}

void GameManager::update() {
  if (!m_is_playing)
    return;

  for (auto& ball : m_balls) {
    ball.update();
  }
  m_paddle.update();
  check_collisions();
}

void GameManager::check_collisions() {
  for (auto& ball : m_balls) {
    SDL_Rect ball_rect = ball.get_rect();

    ball.check_collision(m_paddle);

    for (auto& brick : m_bricks) {
      ball.check_collision(brick, m_score);
    }

    ball.bounce();
    if (ball_rect.y + ball_rect.h > Config::WINDOW_HEIGHT) {
      m_lives--;
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
      int resistance = (x + y) % 5 + 1;
      m_bricks.push_back(Brick(x * Config::BRICK_WIDTH,
                               y * Config::BRICK_HEIGHT, Config::BRICK_WIDTH,
                               Config::BRICK_HEIGHT, m_brick_textures,
                               resistance));
    }
  }
}

void GameManager::reset() {
  m_balls.clear();
  m_balls.push_back(Ball(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2,
                         Config::BALL_RADIUS, Config::BALL_RADIUS,
                         m_ball_texture, Vector2D<double>(1, -1).normalize(),
                         Config::BALL_SPEED));

  m_paddle =
      Paddle(Config::WINDOW_WIDTH / 2, Config::PADDLE_Y, Config::PADDLE_WIDTH,
             Config::PADDLE_HEIGHT, m_paddle_texture, Config::PADDLE_SPEED);

  m_bricks.clear();
  load_level();

  m_score = 0;
  m_lives = Config::LIFE_COUNT;
  m_is_playing = true;
}