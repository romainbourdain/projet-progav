#pragma once

#include <iostream>
#include <vector>

#include "brick.h"
#include "window.h"

class Game {
 public:
  Game();
  ~Game();
  void run() const;
  void handle_events(const SDL_Event& event) const;
  void update() const;
  void render() const;

 private:
  Window m_window;
  std::vector<std::shared_ptr<Brick>> m_bricks;

  void generate_bricks();
};