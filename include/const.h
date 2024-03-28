#pragma once

#include <SDL2/SDL.h>

namespace Constants {
inline constexpr int SCREEN_WIDTH = 1280;
inline constexpr int SCREEN_HEIGHT = 720;

inline constexpr int BRICK_WIDTH = 80;
inline constexpr int BRICK_HEIGHT = 20;

inline constexpr SDL_Color RED = {255, 0, 0, 255};
inline constexpr SDL_Color ORANGE = {255, 127, 40, 255};

inline constexpr SDL_Color BACKGROUND_COLOR = {0, 0, 0, 255};
}  // namespace Constants
