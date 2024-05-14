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

  inline std::vector<std::unique_ptr<Ball>>& get_balls();
  inline Paddle& get_paddle();
  inline std::vector<std::unique_ptr<Brick>>& get_bricks();
  inline int get_score() const;
  inline int get_lives() const;

 private:
  void load_level();

  std::vector<std::unique_ptr<Ball>> m_balls;
  std::unique_ptr<Paddle> m_paddle;
  std::vector<std::unique_ptr<Brick>> m_bricks;

  int m_score;
  int m_lives;
  bool m_is_playing;
};

inline std::vector<std::unique_ptr<Ball>>& GameManager::get_balls() {
  return m_balls;
}

inline Paddle& GameManager::get_paddle() {
  return *m_paddle;
}

inline std::vector<std::unique_ptr<Brick>>& GameManager::get_bricks() {
  return m_bricks;
}

inline int GameManager::get_score() const {
  return m_score;
}

inline int GameManager::get_lives() const {
  return m_lives;
}