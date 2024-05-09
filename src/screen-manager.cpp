#include "screen-manager.h"
#include "sdl-wrapper.h"

#include <memory>

ScreenManager::ScreenManager(SDL_Wrapper& sdl)
    : m_current_screen(nullptr), m_sdl(sdl) {
  switchToTitleScreen();
}

void ScreenManager::switchToTitleScreen() {
  m_current_screen.reset(new TitleScreen(m_sdl));
}

void ScreenManager::render() const {
  if (m_current_screen)
    m_current_screen->render();
}

void ScreenManager::update() {
  if (m_current_screen)
    m_current_screen->update();
}