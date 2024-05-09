#pragma once

#include <SDL.h>
#include "SDLWrapper.h"
#include "screens/TitleScreen.h"
#include "utils.h"

class ScreenManager {
 private:
  std::unique_ptr<TitleScreen> m_titleScreen;
  SDLWrapper& m_sdl;

 public:
  explicit ScreenManager(SDLWrapper& sdl);
  void switchToTitleScreen();
  void render() const;
};