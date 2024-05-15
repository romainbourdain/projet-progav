/**
 * @file config.h
 * @brief Configuration des constantes pour le jeu Breakout.
 */

#pragma once

#include <SDL.h>
#include <cmath>

/**
 * @namespace Config
 * @brief Namespace contenant les constantes de configuration pour le jeu Breakout.
 */
namespace Config {

/** @brief Largeur de la fenêtre du jeu. */
inline constexpr int WINDOW_WIDTH = 800;

/** @brief Hauteur de la fenêtre du jeu. */
inline constexpr int WINDOW_HEIGHT = 600;

/** @brief Nombre de vies initiales du joueur. */
inline constexpr int LIFE_COUNT = 3;

/** @brief Score attribué pour la destruction d'une brique. */
inline constexpr int BRICK_SCORE = 10;

/** @brief Délai entre deux collisions successives pour éviter les collisions multiples. */
inline constexpr float COLLISION_COOLDOWN = 0.1f;

/** @brief Rayon de la balle. */
inline constexpr int BALL_RADIUS = 10;

/** @brief Vitesse initiale de la balle. */
inline constexpr float BALL_SPEED = 7.0f;

/** @brief Largeur de la raquette. */
inline constexpr int PADDLE_WIDTH = 100;

/** @brief Hauteur de la raquette. */
inline constexpr int PADDLE_HEIGHT = 10;

/** @brief Vitesse de déplacement de la raquette. */
inline constexpr int PADDLE_SPEED = 5.0f;

/** @brief Position Y de la raquette par rapport au bas de la fenêtre. */
inline constexpr int PADDLE_Y = WINDOW_HEIGHT - PADDLE_HEIGHT - 50;

/** @brief Largeur d'une brique. */
inline constexpr int BRICK_WIDTH = 80;

/** @brief Hauteur d'une brique. */
inline constexpr int BRICK_HEIGHT = 20;

/** @brief Couleur de la balle (Blanc). */
inline constexpr SDL_Color BALL_COLOR = {255, 255, 255, 255};

/** @brief Couleur de la raquette (Bleu). */
inline constexpr SDL_Color PADDLE_COLOR = {0, 0, 255, 255};

/** @brief Couleur des briques (Rouge). */
inline constexpr SDL_Color BRICK_COLOR = {255, 0, 0, 255};

/** @brief Couleur des bordures des briques (Blanc). */
inline constexpr SDL_Color BRICK_BORDER_COLOR = {255, 255, 255, 255};

/** @brief Couleur de fond de l'écran (Noir). */
inline constexpr SDL_Color BACKGROUND_COLOR = {0, 0, 0, 255};

/** @brief Couleur de premier plan (Blanc). */
inline constexpr SDL_Color FOREGROUND_COLOR = {255, 255, 255, 255};

/** @brief Nombre d'images par seconde (FPS). */
inline constexpr int FRAMES_PER_SECOND = 90;

/** @brief Angle maximal de rebond de la balle en radians. */
inline constexpr double MAX_BOUNCE_ANGLE = M_PI / 3.0f;

}  // namespace Config
