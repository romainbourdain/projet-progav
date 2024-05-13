#include "screens/title-screen.h"
#include "screens/menu-screen.h"
#include "sdl-wrapper.h"

#include <iostream>

TitleScreen::TitleScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl)
    : Screen(screen_manager, sdl),
      m_titleTexture(m_sdl.loadTexture("assets/images/title-screen.png")),
      m_scale(1.0f) {
  m_last_time = SDL_GetTicks();
}

void TitleScreen::render() const {
  int w = 800;
  int h = 600;

  m_sdl.drawTexture(m_titleTexture, 0, 0, w, h);
  m_sdl.drawText("Press Space to Start", w / 2, h - 20, {255, 255, 255, 255});
}

void TitleScreen::update() {}

void TitleScreen::handleEvent(const SDL_Event& event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_SPACE:
        m_screen_manager.changeScreen(
            std::make_shared<MenuScreen>(m_screen_manager, m_sdl));
        break;
    }
  }
}
