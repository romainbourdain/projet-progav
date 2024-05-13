#pragma once

#include "screens/screen.h"

class TitleScreen : public Screen {
 public:
  TitleScreen(ScreenManager& screen_manager);
  void handle_events() override;
  void update() override;
  void render() override;
};