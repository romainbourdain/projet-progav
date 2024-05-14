#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <chrono>
#include <memory>
#include <string>
#include <vector>

// Alias pour les pointeurs de ressources SDL
using SDL_Texture_ptr = std::shared_ptr<SDL_Texture>;
using TTF_Font_ptr = std::shared_ptr<TTF_Font>;
using SDL_Surface_ptr =
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
using SDL_Window_ptr =
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using SDL_Renderer_ptr =
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

/**
 * @brief Classe wrapper pour SDL.
 * 
 * Cette classe encapsule les fonctions de SDL pour simplifier leur utilisation.
 */
class SDL_Wrapper {
 public:
  /**
   * @brief Classe d'exception spécifique à SDL_Wrapper.
   */
  class SDLException : public std::runtime_error {
   public:
    /**
     * @brief Constructeur de l'exception SDLException.
     * @param message Message d'erreur.
     */
    SDLException(const std::string& message) : std::runtime_error(message) {}
  };

  /**
   * @brief Enumération pour définir l'origine d'un rectangle.
   */
  enum class Origin { TOP_LEFT, CENTER };

  /**
   * @brief Initialise SDL, la fenêtre et le renderer.
   * @param title Titre de la fenêtre.
   * @param width Largeur de la fenêtre.
   * @param height Hauteur de la fenêtre.
   */
  static void init(const std::string& title, int width, int height);

  /**
   * @brief Quitte SDL et nettoie les ressources.
   */
  static void quit();

  /**
  * @brief Obtient la largeur de la fenêtre.
  * @return Largeur de la fenêtre.
 */
  static int get_window_width();

  /**
   * @brief Obtient la hauteur de la fenêtre.
   * @return Hauteur de la fenêtre.
   */
  static int get_window_height();

  /**
   * @brief Charge une texture depuis un fichier.
   * @param path Chemin du fichier de texture.
   * @return SDL_Texture_ptr Texture chargée.
   */
  static SDL_Texture_ptr load_texture(const std::string& path);

  /**
   * @brief Charge une police depuis un fichier.
   * @param path Chemin du fichier de police.
   * @param fontSize Taille de la police.
   * @return TTF_Font_ptr Police chargée.
   */
  static TTF_Font_ptr load_font(const std::string& path, int fontSize);

  /**
   * @brief Rend une texture à l'écran.
   * @param texture Texture à rendre.
   * @param x Position x.
   * @param y Position y.
   * @param width Largeur de la texture.
   * @param height Hauteur de la texture.
   * @param origin Origine de la texture (par défaut TOP_LEFT).
   */
  static void render_texture(SDL_Texture_ptr texture, int x, int y, int width,
                             int height, Origin origin = Origin::TOP_LEFT);

  /**
   * @brief Rend du texte à l'écran.
   * @param text Texte à rendre.
   * @param font Police à utiliser.
   * @param x Position x.
   * @param y Position y.
   * @param color Couleur du texte.
   * @param origin Origine du texte (par défaut TOP_LEFT).
   */
  static void render_text(const std::string& text, TTF_Font_ptr& font, int x,
                          int y, SDL_Color color,
                          Origin origin = Origin::TOP_LEFT);

  /**
   * @brief Dessine un rectangle à l'écran.
   * @param x Position x.
   * @param y Position y.
   * @param width Largeur du rectangle.
   * @param height Hauteur du rectangle.
   * @param color Couleur du rectangle.
   * @param fill Remplit le rectangle si true (par défaut true).
   * @param origin Origine du rectangle (par défaut TOP_LEFT).
   */
  static void draw_rect(int x, int y, int width, int height, SDL_Color color,
                        bool fill = true, Origin origin = Origin::TOP_LEFT);

  /**
   * @brief Nettoie l'écran.
   */
  static void clear();

  /**
   * @brief Met à jour le rendu de l'écran.
   */
  static void present();

  /**
   * @brief Construit un rectangle avec une origine spécifiée.
   * @param x Position x.
   * @param y Position y.
   * @param width Largeur du rectangle.
   * @param height Hauteur du rectangle.
   * @param origin Origine du rectangle.
   * @return SDL_Rect Rectangle calculé.
   */
  static SDL_Rect get_rect_with_origin(int x, int y, int width, int height,
                                       Origin origin);

  // Gestion des entrées
  /**
   * @brief Traite les entrées utilisateur.
   */
  static void process_input();

  /**
   * @brief Vérifie si une touche est enfoncée.
   * @param key Code de la touche.
   * @return true si la touche est enfoncée, false sinon.
   */
  inline static bool is_key_pressed(SDL_Scancode key);

  /**
   * @brief Vérifie si un bouton de la souris est enfoncé.
   * @param button Code du bouton.
   * @return true si le bouton est enfoncé, false sinon.
   */
  inline static bool is_mouse_button_pressed(Uint32 button);

  /**
   * @brief Obtient la position x de la souris.
   * @return Position x de la souris.
   */
  inline static int get_mouse_x();

  /**
   * @brief Obtient la position y de la souris.
   * @return Position y de la souris.
   */
  inline static int get_mouse_y();

  // Gestion des FPS
  /**
   * @brief Limite le nombre de FPS.
   * @param fps Nombre de FPS.
   */
  static void limit_fps(int fps);

 private:
  SDL_Wrapper() = default;

  static SDL_Window_ptr s_window;     /**< Fenêtre SDL. */
  static SDL_Renderer_ptr s_renderer; /**< Renderer SDL. */

  // États des entrées
  static std::shared_ptr<std::vector<Uint8>>
      s_key_state;             /**< État des touches du clavier. */
  static Uint32 s_mouse_state; /**< État des boutons de la souris. */
  static int s_mouse_x;        /**< Position x de la souris. */
  static int s_mouse_y;        /**< Position y de la souris. */

  // Limitation du taux de rafraîchissement
  static std::chrono::steady_clock::time_point
      s_frame_last;         /**< Temps de la dernière frame. */
  static int s_frame_delay; /**< Délai entre les frames. */
};

// Inline functions

inline bool SDL_Wrapper::is_key_pressed(SDL_Scancode key) {
  return s_key_state->data()[key];
}

inline bool SDL_Wrapper::is_mouse_button_pressed(Uint32 button) {
  return (s_mouse_state & SDL_BUTTON(button)) != 0;
}

inline int SDL_Wrapper::get_mouse_x() {
  return s_mouse_x;
}

inline int SDL_Wrapper::get_mouse_y() {
  return s_mouse_y;
}
