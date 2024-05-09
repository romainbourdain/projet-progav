#pragma once

#include <SDL.h>

#include "screens/title-screen.h"
#include "sdl-wrapper.h"

class ScreenManager {
 private:
  std::unique_ptr<TitleScreen> m_titleScreen;
  SDLWrapper& m_sdl;

 public:
  explicit ScreenManager(SDLWrapper& sdl);
  void switchToTitleScreen();
  void render() const;
};