#pragma once

#include <SDL2/SDL.h>

class TitleScreen {
 private:
  SDL_Renderer* renderer;
  SDL_Texture* titleTexture;

 public:
  void init(SDL_Renderer* renderer);
  void render();
  void loadMedia();
};