#pragma once

#include <SDL.h>

namespace Config {

inline constexpr int WINDOW_WIDTH = 800;
inline constexpr int WINDOW_HEIGHT = 600;

inline constexpr int BALL_RADIUS = 15;
inline constexpr float BALL_SPEED = 7.0f;

inline constexpr int PADDLE_WIDTH = 100;
inline constexpr int PADDLE_HEIGHT = 20;
inline constexpr int PADDLE_SPEED = 5.0f;

inline constexpr int BRICK_WIDTH = 80;
inline constexpr int BRICK_HEIGHT = 20;

inline constexpr SDL_Color BALL_COLOR = {255, 255, 255, 255};          // Blanc
inline constexpr SDL_Color PADDLE_COLOR = {0, 0, 255, 255};            // Bleu
inline constexpr SDL_Color BRICK_COLOR = {255, 0, 0, 255};             // Rouge
inline constexpr SDL_Color BRICK_BORDER_COLOR = {255, 255, 255, 255};  // Blanc
inline constexpr SDL_Color BACKGROUND_COLOR = {0, 0, 0, 255};          // Noir
inline constexpr SDL_Color FOREGROUND_COLOR = {255, 255, 255, 255};    // Blanc

inline constexpr int FRAMES_PER_SECOND = 60;

inline constexpr float MAX_BOUNCE_ANGLE = 75.0f;

}  // namespace Config
