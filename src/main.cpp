#include <SDL.h>
#include <cassert>
#include <iostream>

#include "lib/const.h"

#include "game.h"
#include "window.h"

int main(int argc, char** argv) {
  Game game;

  game.run();

  return EXIT_SUCCESS;
}
