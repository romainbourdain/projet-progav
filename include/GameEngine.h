#pragma once

#include <SDL.h>
#include <string>

#include "SDLWrapper.h"
#include "ScreenManager.h"
#include "util.h"

class GameEngine {
 private:
  bool m_running;
  SDLWrapper_ptr m_sdl;
  std::unique_ptr<ScreenManager> m_screenManager;

 public:
  GameEngine(const std::string& title, int width, int height);
  ~GameEngine();
  void run();
};