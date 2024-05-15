#pragma once

#include "screens/screen.h"
#include "sdl-wrapper.h"

#include <string>
#include <vector>

class MenuScreen : public Screen {
 public:
  MenuScreen(ScreenManager& screen_manager);
  void handle_events() override;
  void update() override;
  void render() override;

 private:
  void load_levels();
  void load_assets();

  std::vector<std::string> m_levels;
  int m_selected_level;

  TTF_Font_ptr m_font;

  bool m_is_key_pressed;
};