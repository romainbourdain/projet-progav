#include "entities/brick.h"
#include <iostream>
#include "config.h"

Brick::Brick(int x, int y, int width, int height,
             std::vector<SDL_Texture_ptr>& textures, int resistance)
    : Entity(x, y, width, height, textures[resistance - 1]),
      m_resistance(resistance),
      m_textures(textures) {}

void Brick::update() {}

void Brick::render() const {
  if (is_destroyed())
    return;

  SDL_Wrapper::render_texture(m_texture, m_rect.x, m_rect.y, m_rect.w, m_rect.h,
                              SDL_Wrapper::Origin::TOP_LEFT);
}

void Brick::destroy() {
  m_resistance--;
  set_texture();
}

void Brick::set_texture() {
  m_texture = 0 <= m_resistance - 1 < m_textures.size()
                  ? m_textures[m_resistance - 1]
                  : nullptr;
}