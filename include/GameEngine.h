#pragma once

#include <SDL2/SDL.h>
#include "ScreenManager.h"

class GameEngine {
 private:
  bool running;
  SDL_Window* window;
  SDL_Renderer* renderer;
  ScreenManager screenManager;

 public:
  bool init(const char* title, int width, int height);
  bool run();
  bool cleanup();
};