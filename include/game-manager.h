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
  inline bool is_game_over() const;

  inline void pause();
  inline void resume();

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
  bool m_is_game_over;
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

inline bool GameManager::is_game_over() const {
  return m_is_game_over;
}

inline void GameManager::pause() {
  m_is_playing = false;
}

inline void GameManager::resume() {
  m_is_playing = true;
}