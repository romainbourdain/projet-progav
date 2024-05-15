/**
 * @file screen-manager.h
 * @brief Déclaration de la classe ScreenManager, qui gère les différents écrans du jeu.
 */

#pragma once

#include "screens/screen.h"

#include <iostream>

/**
 * @class ScreenManager
 * @brief Gère les différents écrans du jeu Breakout.
 * 
 * La classe ScreenManager permet de changer d'écran et de déléguer la gestion des événements, la mise à jour et le rendu à l'écran actif.
 */
class ScreenManager {
 public:
  /**
   * @brief Change l'écran actuellement affiché.
   * 
   * @param screen Pointeur partagé vers le nouvel écran à afficher.
   */
  inline void change_screen(ScreenPtr screen);

  /**
   * @brief Gère les événements d'entrée pour l'écran actuel.
   */
  void handle_events();

  /**
   * @brief Met à jour l'état de l'écran actuel.
   */
  void update();

  /**
   * @brief Rend l'écran actuel à l'écran.
   */
  void render();

 private:
  ScreenPtr
      m_current_screen; /**< Pointeur partagé vers l'écran actuellement affiché. */
};

inline void ScreenManager::change_screen(ScreenPtr screen) {
  m_current_screen = screen;
}
