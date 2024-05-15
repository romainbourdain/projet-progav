/**
 * @file paddle.h
 * @brief Déclaration de la classe Paddle, qui représente la raquette contrôlée par le joueur dans le jeu.
 */

#pragma once

#include "entities/entity.h"

/**
 * @class Paddle
 * @brief Représente la raquette contrôlée par le joueur dans le jeu Breakout.
 * 
 * La classe Paddle hérite de la classe Entity et gère le mouvement et le rendu de la raquette.
 */
class Paddle : public Entity {
 public:
  /**
   * @brief Constructeur de la classe Paddle.
   * 
   * @param x La position x de la raquette.
   * @param y La position y de la raquette.
   * @param width La largeur de la raquette.
   * @param height La hauteur de la raquette.
   * @param texture La texture de la raquette.
   * @param speed La vitesse de déplacement de la raquette.
   */
  Paddle(int x, int y, int width, int height, SDL_Texture_ptr& texture,
         int speed);

  /**
   * @brief Met à jour la position et l'état de la raquette.
   */
  void update() override;

  /**
   * @brief Rend la raquette à l'écran.
   */
  void render() const override;

  /**
   * @brief Définit la position de la raquette.
   * @param x La nouvelle position x de la raquette.
   * @param y La nouvelle position y de la raquette.
   */
  inline void set_position(int x, int y);

 private:
  int m_speed; /**< La vitesse de déplacement de la raquette. */
};

inline void Paddle::set_position(int x, int y) {
  m_rect.x = x;
  m_rect.y = y;
}
