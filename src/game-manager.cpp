#include "game-manager.h"
#include "config.h"

#include <fstream>
#include <iostream>
#include <sstream>

GameManager::GameManager(std::string& level_path)
    : m_paddle_texture(SDL_Wrapper::load_texture("assets/images/paddle.png")),
      m_ball_texture(SDL_Wrapper::load_texture("assets/images/ball.png")),
      m_brick_textures(
          {SDL_Wrapper::load_texture("assets/images/brick-1.png"),
           SDL_Wrapper::load_texture("assets/images/brick-2.png"),
           SDL_Wrapper::load_texture("assets/images/brick-3.png"),
           SDL_Wrapper::load_texture("assets/images/brick-4.png"),
           SDL_Wrapper::load_texture("assets/images/brick-5.png")}),
      m_background_texture(
          SDL_Wrapper::load_texture("assets/images/game-background.png")),

      m_paddle(Config::WINDOW_WIDTH / 2, Config::PADDLE_Y, Config::PADDLE_WIDTH,
               Config::PADDLE_HEIGHT, m_paddle_texture, Config::PADDLE_SPEED),
      m_level_path(level_path),
      m_score(0),
      m_lives(Config::LIFE_COUNT),
      m_is_playing(true),
      m_is_game_over(false) {
  m_balls.push_back(Ball(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2,
                         Config::BALL_RADIUS, Config::BALL_RADIUS,
                         m_ball_texture, Vector2D<double>(1, -1).normalize(),
                         Config::BALL_SPEED));
  load_level();
  std::cout << "GameManager created" << std::endl;
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
        m_is_playing = false;
        m_is_game_over = true;
      }
    }
  }
}

void GameManager::load_level() {

  std::ifstream level_file("levels/" + m_level_path);
  if (!level_file.is_open()) {
    throw std::runtime_error("Failed to open level file: " + m_level_path);
  }

  std::string line;
  int row = 0;

  while (std::getline(level_file, line)) {
    for (size_t col = 0; col < line.size() && col < 10; col++) {
      char brick_char = line[col];
      if (brick_char >= '1' && brick_char <= '5') {
        int resistance = brick_char - '0';
        m_bricks.push_back(Brick(col * Config::BRICK_WIDTH,
                                 row * Config::BRICK_HEIGHT,
                                 Config::BRICK_WIDTH, Config::BRICK_HEIGHT,
                                 m_brick_textures, resistance));
      }
    }
    row++;
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
  m_is_game_over = false;
}

void GameManager::render() const {
  SDL_Wrapper::render_texture(m_background_texture, 0, 0, Config::WINDOW_WIDTH,
                              Config::WINDOW_HEIGHT,
                              SDL_Wrapper::Origin::TOP_LEFT);

  for (const auto& brick : m_bricks) {
    brick.render();
  }

  m_paddle.render();

  for (const auto& ball : m_balls) {
    ball.render();
  }
}