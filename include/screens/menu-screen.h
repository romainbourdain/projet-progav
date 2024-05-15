/**
 * @file menu-screen.h
 * @brief Déclaration de la classe MenuScreen, qui représente l'écran de menu pour la sélection des niveaux.
 */

#pragma once

#include "screens/screen.h"
#include "sdl-wrapper.h"

#include <string>
#include <vector>

/**
 * @class MenuScreen
 * @brief Représente l'écran de menu pour la sélection des niveaux dans le jeu Breakout.
 * 
 * La classe MenuScreen gère l'affichage des niveaux disponibles et permet la sélection d'un niveau à l'aide du clavier.
 */
class MenuScreen : public Screen {
 public:
  /**
   * @brief Constructeur de la classe MenuScreen.
   * 
   * @param screen_manager Référence vers le gestionnaire d'écrans.
   */
  MenuScreen(ScreenManager& screen_manager);

  /**
   * @brief Gère les événements d'entrée.
   */
  void handle_events() override;

  /**
   * @brief Met à jour l'état du menu.
   */
  void update() override;

  /**
   * @brief Rend le menu à l'écran.
   */
  void render() override;

 private:
  /**
   * @brief Charge les niveaux disponibles depuis le répertoire des niveaux.
   */
  void load_levels();

  /**
   * @brief Charge les ressources nécessaires pour le menu.
   */
  void load_assets();

  std::vector<std::string> m_levels; /**< Liste des niveaux disponibles. */
  int m_selected_level;              /**< Niveau actuellement sélectionné. */

  TTF_Font_ptr m_font; /**< Police utilisée pour afficher les niveaux. */

  bool
      m_is_key_pressed; /**< Indicateur pour éviter les doubles pressions de touche. */
};
