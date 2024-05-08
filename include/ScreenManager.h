#pragma once

#include <SDL2/SDL.h>
#include "screens/TitleScreen.h"

class ScreenManager {
 private:
  TitleScreen titleScreen;

 public:
  void init(SDL_Renderer* renderer);
  void render();
};