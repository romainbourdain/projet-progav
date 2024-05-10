#pragma once

#include <SDL.h>

#include "screen-manager.h"
#include "screens/screen.h"
#include "sdl-wrapper.h"

class TitleScreen : public Screen {
 private:
  SDL_Texture_ptr m_titleTexture;
  TTF_Font_ptr m_titleFont;

  float m_scale;
  Uint32 m_last_time;

 public:
  explicit TitleScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl);
  void render() const;
  void update();
  void handleEvent(const SDL_Event& event);
};