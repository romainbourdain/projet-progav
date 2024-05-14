#include "game.h"
#include "sdl-wrapper.h"

int main(int argc, char* argv[]) {

  Game game("Casse Brique", 800, 600);
  game.run();

  SDL_Wrapper::quit();

  return 0;
}