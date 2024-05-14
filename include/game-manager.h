#pragma once

#include "entities/ball.h"
#include "entities/brick.h"
#include "entities/paddle.h"

#include <memory>
#include <vector>

class GameManager {
 public:
  GameManager();
  void update();
  void check_collisions();
  void reset();

  inline std::vector<Ball>& get_balls();
  inline Paddle& get_paddle();
  inline std::vector<Brick>& get_bricks();
  inline int get_score() const;
  inline int get_lives() const;
  inline bool is_playing() const;

 private:
  void load_level();

  SDL_Texture_ptr m_paddle_texture;
  SDL_Texture_ptr m_ball_texture;
  std::vector<SDL_Texture_ptr> m_brick_textures;

  std::vector<Ball> m_balls;
  Paddle m_paddle;
  std::vector<Brick> m_bricks;

  int m_score;
  int m_lives;
  bool m_is_playing;
};

inline std::vector<Ball>& GameManager::get_balls() {
  return m_balls;
}

inline Paddle& GameManager::get_paddle() {
  return m_paddle;
}

inline std::vector<Brick>& GameManager::get_bricks() {
  return m_bricks;
}

inline int GameManager::get_score() const {
  return m_score;
}

inline int GameManager::get_lives() const {
  return m_lives;
}

inline bool GameManager::is_playing() const {
  return m_is_playing;
}