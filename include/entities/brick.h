/**
 * @file brick.h
 * @brief Déclaration de la classe Brick, qui représente une brique dans le jeu.
 */

#pragma once

#include <vector>
#include "entities/entity.h"

/**
 * @class Brick
 * @brief Représente une brique dans le jeu Breakout.
 * 
 * La classe Brick hérite de la classe Entity et gère le rendu, l'état et les collisions des briques.
 */
class Brick : public Entity {
 public:
  /**
   * @brief Constructeur de la classe Brick.
   * 
   * @param x La position x de la brique.
   * @param y La position y de la brique.
   * @param width La largeur de la brique.
   * @param height La hauteur de la brique.
   * @param textures Les textures de la brique correspondant à ses différents états.
   * @param resistance La résistance initiale de la brique.
   */
  Brick(int x, int y, int width, int height,
        std::vector<SDL_Texture_ptr>& textures, int resistance);

  /**
   * @brief Met à jour l'état de la brique.
   */
  void update() override;

  /**
   * @brief Rend la brique à l'écran.
   */
  void render() const override;

  /**
   * @brief Vérifie si la brique est détruite.
   * @return true si la brique est détruite, false sinon.
   */
  inline bool is_destroyed() const;

  /**
   * @brief Diminue la résistance de la brique et la détruit si la résistance est épuisée.
   */
  void destroy();

 private:
  int m_resistance; /**< La résistance actuelle de la brique. */
  std::vector<SDL_Texture_ptr>&
      m_textures; /**< Les textures de la brique pour ses différents états. */

  /**
   * @brief Met à jour la texture de la brique en fonction de sa résistance actuelle.
   */
  void set_texture();
};

inline bool Brick::is_destroyed() const {
  return m_resistance <= 0;
}
