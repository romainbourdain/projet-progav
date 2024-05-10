#include "screen-manager.h"
#include "screens/menu-screen.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

#include <memory>

ScreenManager::ScreenManager(SDL_Wrapper& sdl) : m_sdl(sdl) {}

void ScreenManager::init() {
  m_current_screen = std::make_shared<TitleScreen>(*this, m_sdl);
}

void ScreenManager::render() const {
  if (m_current_screen)
    m_current_screen->render();
}

void ScreenManager::update() {
  if (m_current_screen)
    m_current_screen->update();
}

void ScreenManager::handleEvent(const SDL_Event& event) {
  if (m_current_screen)
    m_current_screen->handleEvent(event);
}

void ScreenManager::changeScreen(std::shared_ptr<Screen> screen) {
  m_current_screen = std::move(screen);
}