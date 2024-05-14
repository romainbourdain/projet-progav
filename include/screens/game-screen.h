#pragma once

#include "game-manager.h"
#include "screens/screen.h"

#include <iostream>

class GameScreen : public Screen {
 public:
  GameScreen(ScreenManager& screen_manager);
  void handle_events() override;
  void update() override;
  void render() override;

 private:
  GameManager m_game_manager;
  TTF_Font_ptr m_font;
};