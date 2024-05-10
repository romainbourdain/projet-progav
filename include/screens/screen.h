#pragma once
#include "sdl-wrapper.h"

class ScreenManager;  // to avoid circular dependency

class Screen {
 protected:
  SDL_Wrapper& m_sdl;
  ScreenManager& m_screen_manager;

 public:
  explicit Screen(ScreenManager& screen_manager, SDL_Wrapper& sdl)
      : m_sdl(sdl), m_screen_manager(screen_manager) {}
  virtual ~Screen() = default;

  virtual void render() const = 0;
  virtual void update() = 0;
  virtual void handleEvent(const SDL_Event& event) = 0;
};