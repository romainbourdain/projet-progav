#pragma once

#include <string>
#include <vector>

#include "screen-manager.h"
#include "screen.h"
#include "sdl-wrapper.h"

class MenuScreen : public Screen {
 private:
  std::vector<std::string> m_levels;
  int m_selected_level;

 public:
  explicit MenuScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl);
  void render() const;
  void update();
  void selectNextLevel();
  void selectPreviousLevel();
  void handleEvent(const SDL_Event& event);
};