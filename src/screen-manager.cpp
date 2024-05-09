#include "screen-manager.h"
#include "sdl-wrapper.h"

#include <memory>

ScreenManager::ScreenManager(SDLWrapper& sdl)
    : m_titleScreen(std::make_unique<TitleScreen>(sdl)), m_sdl(sdl) {}

void ScreenManager::switchToTitleScreen() {}

void ScreenManager::render() const {
  if (m_titleScreen)
    m_titleScreen->render();
}