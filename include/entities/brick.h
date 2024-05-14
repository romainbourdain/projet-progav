#pragma once

#include "entities/entity.h"

class Brick : public Entity {
 public:
  Brick(int x, int y, int width, int height);

  void update() override;
  void render() const override;

  inline bool is_destroyed() const;
  inline void destroy();

 private:
  bool m_destroyed;
};

inline bool Brick::is_destroyed() const {
  return m_destroyed;
}

inline void Brick::destroy() {
  m_destroyed = true;
}