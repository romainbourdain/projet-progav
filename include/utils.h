#pragma once

#include <SDL.h>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

template <typename T>
inline void errorAndExit(const T& msg, const char* file, int line) {
  std::cerr << "Error in : " << file << " at line " << line << std::endl;
  std::cerr << "Error : " << msg << std::endl;
  std::exit(EXIT_FAILURE);
}

template <typename T>
inline void assertAndError(bool condition, const T& msg, const char* file,
                           int line) {
  if (!condition) {
    errorAndExit(msg, file, line);
  }
}

#define ERROR_AND_EXIT(msg) errorAndExit(msg, __FILE__, __LINE__)
#define ASSERT_AND_ERROR(condition, msg) \
  assertAndError(condition, msg, __FILE__, __LINE__)