#pragma once

#include <SDL.h>
#include <cmath>

namespace Config {

inline constexpr int WINDOW_WIDTH = 800;
inline constexpr int WINDOW_HEIGHT = 600;

inline constexpr int LIFE_COUNT = 3;
inline constexpr int BRICK_SCORE = 10;

inline constexpr float COLLISION_COOLDOWN = 0.1f;

inline constexpr int BALL_RADIUS = 10;
inline constexpr float BALL_SPEED = 7.0f;

inline constexpr int PADDLE_WIDTH = 100;
inline constexpr int PADDLE_HEIGHT = 10;
inline constexpr int PADDLE_SPEED = 5.0f;
inline constexpr int PADDLE_Y = WINDOW_HEIGHT - PADDLE_HEIGHT - 50;

inline constexpr int BRICK_WIDTH = 80;
inline constexpr int BRICK_HEIGHT = 20;

inline constexpr SDL_Color BALL_COLOR = {255, 255, 255, 255};          // Blanc
inline constexpr SDL_Color PADDLE_COLOR = {0, 0, 255, 255};            // Bleu
inline constexpr SDL_Color BRICK_COLOR = {255, 0, 0, 255};             // Rouge
inline constexpr SDL_Color BRICK_BORDER_COLOR = {255, 255, 255, 255};  // Blanc
inline constexpr SDL_Color BACKGROUND_COLOR = {0, 0, 0, 255};          // Noir
inline constexpr SDL_Color FOREGROUND_COLOR = {255, 255, 255, 255};    // Blanc

inline constexpr int FRAMES_PER_SECOND = 90;

inline constexpr double MAX_BOUNCE_ANGLE = M_PI / 3.0f;

}  // namespace Config
