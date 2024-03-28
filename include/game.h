#pragma once

#include <iostream>
#include <memory>
#include <vector>

#include "brick.h"
#include "window.h"

class Game {
 public:
  Game();
  ~Game();
  void run();
  void handle_events(const SDL_Event& event);
  void update() const;
  void render() const;

 private:
  bool m_running;
  Window m_window;

  std::vector<std::shared_ptr<Brick>> m_bricks;

  void generate_bricks();
};