/**
 * @file title-screen.h
 * @brief Déclaration de la classe TitleScreen, qui représente l'écran titre du jeu.
 */

#pragma once

#include "screens/screen.h"
#include "sdl-wrapper.h"

#include <string>

/**
 * @class TitleScreen
 * @brief Représente l'écran titre du jeu Breakout.
 * 
 * La classe TitleScreen gère l'affichage de l'écran titre, y compris le rendu du texte et des images.
 */
class TitleScreen : public Screen {
 public:
  /**
   * @brief Constructeur de la classe TitleScreen.
   * 
   * @param screen_manager Référence vers le gestionnaire d'écrans.
   */
  TitleScreen(ScreenManager& screen_manager);

  /**
   * @brief Gère les événements d'entrée pour l'écran titre.
   */
  void handle_events() override;

  /**
   * @brief Met à jour l'état de l'écran titre.
   */
  void update() override;

  /**
   * @brief Rend l'écran titre à l'écran.
   */
  void render() override;

 private:
  std::string
      m_subtitle_text; /**< Texte du sous-titre affiché sur l'écran titre. */
  SDL_Color m_text_color;       /**< Couleur du texte. */
  TTF_Font_ptr m_font;          /**< Police utilisée pour le texte. */
  SDL_Texture_ptr m_background; /**< Texture de fond de l'écran titre. */

  /**
   * @brief Charge les ressources nécessaires pour l'écran titre.
   */
  void load_assets();
};
