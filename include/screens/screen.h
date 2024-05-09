#pragma once
#include "sdl-wrapper.h"

class Screen {
 protected:
  SDL_Wrapper& m_sdl;

 public:
  explicit Screen(SDL_Wrapper& sdl) : m_sdl(sdl) {}

  virtual void render() const = 0;
  virtual void update() = 0;
};