#pragma once

#include "screens/screen.h"
#include "sdl-wrapper.h"

#include <string>

class TitleScreen : public Screen {
 public:
  TitleScreen(ScreenManager& screen_manager);
  void handle_events() override;
  void update() override;
  void render() override;

 private:
  std::string m_subtitle_text;
  SDL_Color m_text_color;
  TTF_Font_ptr m_font;
  SDL_Texture_ptr m_background;

  void load_assets();
};