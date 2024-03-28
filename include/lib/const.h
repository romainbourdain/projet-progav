#pragma once

#include <SDL.h>
#include <array>

#include "colors.h"

namespace Constants {
inline constexpr int SCREEN_WIDTH = 1280;
inline constexpr int SCREEN_HEIGHT = 720;

inline constexpr int BRICKS_PER_ROW = 16;
inline constexpr int BRICKS_PER_COL = 3;
inline constexpr int BRICK_WIDTH = 80;
inline constexpr int BRICK_HEIGHT = 20;
inline constexpr int BRICK_BORDER_WIDTH = 1;

inline constexpr SDL_Color BACKGROUND_COLOR = Colors::BLACK;
inline constexpr std::array<SDL_Color, 4> BRICK_COLORS = {
    Colors::RED, Colors::ORANGE, Colors::GREEN, Colors::BLUE};
inline constexpr SDL_Color BRICK_BORDER = Colors::WHITE;
}  // namespace Constants