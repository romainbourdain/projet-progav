#include "screens/screen-manager.h"

void ScreenManager::handle_events() {
  if (m_current_screen)
    m_current_screen->handle_events();
}

void ScreenManager::update() {
  if (m_current_screen)
    m_current_screen->update();
}

void ScreenManager::render() {
  if (m_current_screen)
    m_current_screen->render();
}