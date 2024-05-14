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
  TTF_Font_ptr m_title_font;
  TTF_Font_ptr m_subtitle_font;

  SDL_Texture_ptr m_score;
  SDL_Texture_ptr m_lives;
};