#pragma once

#include "screens/screen-manager.h"

#include <string>

class Game {
 public:
  Game(const std::string& title, int width, int height);
  ~Game();
  void run();
  void quit();

 private:
  void handle_events();
  void update();
  void render();

  ScreenManager m_screen_manager;
  bool m_is_running;
};