#pragma once
#include <SDL.h>
#include <cstdlib>
#include <iostream>

template <typename Condition, typename Message>
inline void Assert(Condition condition, Message message) {
  if (!condition) {
    std::cerr << "Assertion failed: " << message << std::endl;
    throw std::runtime_error("Assertion failed");
  }
}

template <typename Condition, typename Message>
inline void AssertSDL(Condition condition, Message message) {
  if (!condition) {
    std::cerr << "Assertion failed: " << message
              << "\n Error: " << SDL_GetError() << std::endl;
    throw std::runtime_error("Assertion failed");
  }
}