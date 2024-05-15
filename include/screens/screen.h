/**
 * @file screen.h
 * @brief Déclaration de la classe Screen, qui sert de classe de base pour tous les écrans du jeu.
 */

#pragma once

#include <iostream>
#include <memory>

class ScreenManager;

/**
 * @class Screen
 * @brief Classe de base abstraite pour tous les écrans du jeu Breakout.
 * 
 * La classe Screen définit l'interface commune pour tous les écrans du jeu, tels que les menus, l'écran de jeu principal, etc.
 */
class Screen {
 public:
  /**
   * @brief Destructeur virtuel par défaut.
   */
  virtual ~Screen() = default;

  /**
   * @brief Gère les événements d'entrée.
   */
  virtual void handle_events() = 0;

  /**
   * @brief Met à jour l'état de l'écran.
   */
  virtual void update() = 0;

  /**
   * @brief Rend l'écran à l'écran.
   */
  virtual void render() = 0;

 protected:
  /**
   * @brief Constructeur protégé de la classe Screen.
   * 
   * @param screen_manager Référence vers le gestionnaire d'écrans.
   */
  Screen(ScreenManager& screen_manager) : m_screen_manager(screen_manager) {}

  ScreenManager&
      m_screen_manager; /**< Référence vers le gestionnaire d'écrans. */
};

/**
 * @typedef ScreenPtr
 * @brief Alias pour un pointeur partagé vers un écran.
 */
using ScreenPtr = std::shared_ptr<Screen>;
