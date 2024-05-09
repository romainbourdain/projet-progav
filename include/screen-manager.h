#pragma once

#include <SDL.h>

#include "screens/screen.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

class ScreenManager {
 private:
  std::unique_ptr<Screen> m_current_screen;
  SDL_Wrapper& m_sdl;

 public:
  explicit ScreenManager(SDL_Wrapper& sdl);
  void switchToTitleScreen();
  void render() const;
  void update();
};