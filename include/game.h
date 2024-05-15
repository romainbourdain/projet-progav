/**
 * @file game.h
 * @brief Déclaration de la classe Game, qui gère le cycle de vie principal du jeu Breakout.
 */

#pragma once

#include "screens/screen-manager.h"

#include <string>

/**
 * @class Game
 * @brief Gère le cycle de vie principal du jeu Breakout.
 * 
 * La classe Game initialise le jeu, gère la boucle principale, les événements, la mise à jour et le rendu.
 */
class Game {
 public:
  /**
   * @brief Constructeur de la classe Game.
   * 
   * @param title Le titre de la fenêtre du jeu.
   * @param width La largeur de la fenêtre du jeu.
   * @param height La hauteur de la fenêtre du jeu.
   */
  Game(const std::string& title, int width, int height);

  /**
   * @brief Destructeur de la classe Game.
   */
  ~Game();

  /**
   * @brief Lance la boucle principale du jeu.
   */
  void run();

  /**
   * @brief Quitte le jeu et nettoie les ressources.
   */
  void quit();

 private:
  /**
   * @brief Gère les événements d'entrée.
   */
  void handle_events();

  /**
   * @brief Met à jour l'état du jeu.
   */
  void update();

  /**
   * @brief Rend le jeu à l'écran.
   */
  void render();

  ScreenManager m_screen_manager; /**< Gestionnaire des écrans du jeu. */
  bool m_is_running; /**< Indicateur d'état du jeu (en cours ou non). */
};
