/**
 * @file game-manager.h
 * @brief Déclaration de la classe GameManager, qui gère la logique principale du jeu Breakout.
 */

#pragma once

#include "entities/ball.h"
#include "entities/brick.h"
#include "entities/paddle.h"

#include <memory>
#include <string>
#include <vector>

/**
 * @class GameManager
 * @brief Gère la logique principale du jeu Breakout.
 * 
 * La classe GameManager gère les entités du jeu, les collisions, le score, les vies, et l'état du jeu.
 */
class GameManager {
 public:
  /**
   * @brief Constructeur de la classe GameManager.
   * 
   * @param level_path Chemin vers le fichier de niveau à charger.
   */
  GameManager(std::string& level_path);

  /**
   * @brief Met à jour l'état du jeu.
   */
  void update();

  /**
   * @brief Vérifie les collisions entre les entités du jeu.
   */
  void check_collisions();

  /**
   * @brief Réinitialise le jeu.
   */
  void reset();

  /**
   * @brief Rend le jeu à l'écran.
   */
  void render() const;

  /**
   * @brief Obtient le score actuel du joueur.
   * @return Le score actuel du joueur.
   */
  inline int get_score() const;

  /**
   * @brief Obtient le nombre de vies restantes du joueur.
   * @return Le nombre de vies restantes du joueur.
   */
  inline int get_lives() const;

  /**
   * @brief Vérifie si le jeu est en cours.
   * @return true si le jeu est en cours, false sinon.
   */
  inline bool is_playing() const;

  /**
   * @brief Vérifie si le jeu est terminé.
   * @return true si le jeu est terminé, false sinon.
   */
  inline bool is_game_over() const;

  /**
   * @brief Met le jeu en pause.
   */
  inline void pause();

  /**
   * @brief Relance le jeu après une pause.
   */
  inline void resume();

 private:
  /**
   * @brief Charge le niveau à partir du fichier spécifié.
   */
  void load_level();

  SDL_Texture_ptr m_paddle_texture;              /**< Texture de la raquette. */
  SDL_Texture_ptr m_ball_texture;                /**< Texture de la balle. */
  std::vector<SDL_Texture_ptr> m_brick_textures; /**< Textures des briques. */
  SDL_Texture_ptr m_background_texture;          /**< Texture de fond. */

  std::vector<Ball> m_balls;   /**< Liste des balles dans le jeu. */
  Paddle m_paddle;             /**< La raquette contrôlée par le joueur. */
  std::vector<Brick> m_bricks; /**< Liste des briques dans le jeu. */

  std::string m_level_path; /**< Chemin vers le fichier de niveau. */

  int m_score;         /**< Score actuel du joueur. */
  int m_lives;         /**< Nombre de vies restantes du joueur. */
  bool m_is_playing;   /**< Indique si le jeu est en cours. */
  bool m_is_game_over; /**< Indique si le jeu est terminé. */
};

inline int GameManager::get_score() const {
  return m_score;
}

inline int GameManager::get_lives() const {
  return m_lives;
}

inline bool GameManager::is_playing() const {
  return m_is_playing;
}

inline bool GameManager::is_game_over() const {
  return m_is_game_over;
}

inline void GameManager::pause() {
  m_is_playing = false;
}

inline void GameManager::resume() {
  m_is_playing = true;
}
