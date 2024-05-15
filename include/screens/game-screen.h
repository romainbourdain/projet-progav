/**
 * @file game-screen.h
 * @brief Déclaration de la classe GameScreen, qui représente l'écran de jeu principal.
 */

#pragma once

#include "game-manager.h"
#include "screens/screen.h"

#include <iostream>

/**
 * @class GameScreen
 * @brief Représente l'écran de jeu principal dans le jeu Breakout.
 * 
 * La classe GameScreen gère la logique du jeu, y compris la gestion des événements, la mise à jour et le rendu.
 */
class GameScreen : public Screen {
 public:
  /**
   * @brief Constructeur de la classe GameScreen.
   * 
   * @param screen_manager Référence vers le gestionnaire d'écrans.
   * @param level_path Chemin vers le fichier de niveau à charger.
   */
  GameScreen(ScreenManager& screen_manager, std::string& level_path);

  /**
   * @brief Gère les événements d'entrée.
   */
  void handle_events() override;

  /**
   * @brief Met à jour l'état du jeu.
   */
  void update() override;

  /**
   * @brief Rend le jeu à l'écran.
   */
  void render() override;

 private:
  GameManager m_game_manager;   /**< Gestionnaire de jeu. */
  TTF_Font_ptr m_title_font;    /**< Police pour le titre. */
  TTF_Font_ptr m_subtitle_font; /**< Police pour le sous-titre. */

  SDL_Texture_ptr m_score; /**< Texture pour afficher le score. */
  SDL_Texture_ptr m_lives; /**< Texture pour afficher les vies restantes. */

  bool
      m_is_key_pressed; /**< Indicateur pour éviter les doubles pressions de touche. */
};
