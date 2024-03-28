#pragma once
#include <SDL2/SDL.h>
#include <cstdlib>
#include <iostream>

#define ASSERT(condition, message)                                         \
  if (!(condition)) {                                                      \
    std::cerr << "Assertion failed: " << message << "\nFile: " << __FILE__ \
              << "\nLine: " << __LINE__ << std::endl;                      \
    std::exit(EXIT_FAILURE);                                               \
  }

#define ASSERT_SDL(condition, message)                                     \
  if (!(condition)) {                                                      \
    std::cerr << "Assertion failed: " << message << "\nFile: " << __FILE__ \
              << "\nLine: " << __LINE__ << "\n Error: " << SDL_GetError    \
              << std::endl;                                                \
    std::exit(EXIT_FAILURE);                                               \
  }