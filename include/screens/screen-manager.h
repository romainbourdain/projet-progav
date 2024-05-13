#pragma once

#include "screens/screen.h"

class ScreenManager {
 public:
  inline void change_screen(ScreenPtr screen);
  void handle_events();
  void update();
  void render();

 private:
  ScreenPtr m_current_screen;
};

void ScreenManager::change_screen(ScreenPtr screen) {
  m_current_screen = screen;
}