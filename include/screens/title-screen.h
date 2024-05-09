#pragma once

#include <SDL.h>

#include "sdl-wrapper.h"

class TitleScreen {
 private:
  SDLWrapper& m_sdl;
  SDL_Texture_ptr m_titleTexture;
  TTF_Font_ptr m_titleFont;

 public:
  explicit TitleScreen(SDLWrapper& sdl);
  void render() const;
};