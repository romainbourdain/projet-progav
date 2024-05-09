#pragma once

#include <SDL.h>
#include <string>

#include "screen-manager.h"
#include "sdl-wrapper.h"

class GameEngine {
 private:
  bool m_running;
  SDL_Wrapper_ptr m_sdl;
  std::unique_ptr<ScreenManager> m_screenManager;

 public:
  GameEngine(const std::string& title, int width, int height);
  void run();
};