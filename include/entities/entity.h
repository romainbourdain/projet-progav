/**
 * @file entity.h
 * @brief Déclaration de la classe Entity, qui est une classe de base pour toutes les entités du jeu.
 */

#pragma once

#include "sdl-wrapper.h"

/**
 * @class Entity
 * @brief Classe de base pour toutes les entités du jeu Breakout.
 * 
 * La classe Entity fournit une interface commune pour toutes les entités du jeu, telles que les balles, les briques et les paddles.
 */
class Entity {
 public:
  /**
   * @brief Constructeur de la classe Entity.
   * 
   * @param x La position x de l'entité.
   * @param y La position y de l'entité.
   * @param width La largeur de l'entité.
   * @param height La hauteur de l'entité.
   * @param texture La texture de l'entité.
   */
  Entity(int x, int y, int width, int height, SDL_Texture_ptr& texture)
      : m_rect(SDL_Wrapper::get_rect_with_origin(x, y, width, height)),
        m_texture(texture) {}

  /**
   * @brief Destructeur virtuel par défaut de la classe Entity.
   */
  virtual ~Entity() = default;

  /**
   * @brief Met à jour l'état de l'entité.
   */
  virtual void update() = 0;

  /**
   * @brief Rend l'entité à l'écran.
   */
  virtual void render() const = 0;

  /**
   * @brief Obtient le rectangle représentant l'entité.
   * @return Le rectangle représentant l'entité.
   */
  inline SDL_Rect get_rect() const;

 protected:
  SDL_Rect m_rect;           /**< Le rectangle représentant l'entité. */
  SDL_Texture_ptr m_texture; /**< La texture de l'entité. */
};

inline SDL_Rect Entity::get_rect() const {
  return m_rect;
}
