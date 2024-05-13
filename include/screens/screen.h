#pragma once

#include <memory>

class ScreenManager;

class Screen {
 public:
  virtual ~Screen() = default;
  virtual void handle_events() = 0;
  virtual void update() = 0;
  virtual void render() = 0;

 protected:
  Screen(ScreenManager& screen_manager) : m_screen_manager(screen_manager) {}

  ScreenManager& m_screen_manager;
};

using ScreenPtr = std::shared_ptr<Screen>;