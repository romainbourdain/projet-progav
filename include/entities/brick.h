#pragma once

#include <vector>
#include "entities/entity.h"

class Brick : public Entity {
 public:
  Brick(int x, int y, int width, int height,
        std::vector<SDL_Texture_ptr>& textures, int resistance);

  void update() override;
  void render() const override;

  inline bool is_destroyed() const;
  void destroy();

 private:
  int m_resistance;
  std::vector<SDL_Texture_ptr>& m_textures;

  void set_texture();
};

inline bool Brick::is_destroyed() const {
  return m_resistance <= 0;
}