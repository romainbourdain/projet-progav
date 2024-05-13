#pragma once

#include "screens/screen.h"

class GameScreen : public Screen {
 public:
  GameScreen(ScreenManager& screen_manager);
  void handle_events() override;
  void update() override;
  void render() override;
};