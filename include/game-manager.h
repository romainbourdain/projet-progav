#pragma once

#include "entities/ball.h"
#include "entities/brick.h"
#include "entities/paddle.h"

#include <memory>
#include <string>
#include <vector>

class GameManager {
 public:
  GameManager(std::string& level_path);
  void update();
  void check_collisions();
  void reset();
  void render() const;

  inline int get_score() const;
  inline int get_lives() const;
  inline bool is_playing() const;

 private:
  void load_level();

  SDL_Texture_ptr m_paddle_texture;
  SDL_Texture_ptr m_ball_texture;
  std::vector<SDL_Texture_ptr> m_brick_textures;
  SDL_Texture_ptr m_background_texture;

  std::vector<Ball> m_balls;
  Paddle m_paddle;
  std::vector<Brick> m_bricks;

  std::string m_level_path;

  int m_score;
  int m_lives;
  bool m_is_playing;
};

inline int GameManager::get_score() const {
  return m_score;
}

inline int GameManager::get_lives() const {
  return m_lives;
}

inline bool GameManager::is_playing() const {
  return m_is_playing;
}