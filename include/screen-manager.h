#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

#include "screens/screen.h"
#include "sdl-wrapper.h"

class ScreenManager {
 private:
  std::shared_ptr<Screen> m_current_screen;
  SDL_Wrapper& m_sdl;

 public:
  explicit ScreenManager(SDL_Wrapper& sdl);
  void init();
  void render() const;
  void update();
  void handleEvent(const SDL_Event& event);
  void changeScreen(std::shared_ptr<Screen> screen);
};