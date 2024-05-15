#include "config.h"
#include "game.h"
#include "sdl-wrapper.h"

int main() {
  {
    Game game("Casse Brique", Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT);
    game.run();
  }

  SDL_Wrapper::quit();

  return 0;
}