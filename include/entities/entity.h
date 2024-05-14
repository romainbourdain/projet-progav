#pragma once

#include "sdl-wrapper.h"

class Entity {
 public:
  Entity(int x, int y, int width, int height)
      : m_rect(SDL_Wrapper::get_rect_with_origin(x, y, width, height)) {}
  virtual ~Entity() = default;

  virtual void update() = 0;
  virtual void render() const = 0;
  inline SDL_Rect get_rect() const;

 protected:
  SDL_Rect m_rect;
};

inline SDL_Rect Entity::get_rect() const {
  return m_rect;
}