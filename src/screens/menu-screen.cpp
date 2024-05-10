#include "screens/menu-screen.h"

MenuScreen::MenuScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl)
    : Screen(screen_manager, sdl),
      m_levels(),
      m_selected_level(0),
      m_font(m_sdl.loadFont("../assets/fonts/Minecraft.ttf", 24)) {
  m_levels.push_back("Level 1");
  m_levels.push_back("Level 2");
  m_levels.push_back("Level 3");
}

void MenuScreen::render() const {
  for (int i = 0; i < m_levels.size(); i++) {
    m_sdl.drawText(m_font, m_levels[i], 100, 100 + i * 50,
                   {255, 255, 255, 255});
    if (i == m_selected_level) {
      m_sdl.drawText(m_font, ">", 80, 100 + i * 50, {255, 255, 255, 255});
    }
  }
}

void MenuScreen::handleEvent(const SDL_Event& event) {
  if (event.type == SDL_KEYDOWN) {
    switch (event.key.keysym.sym) {
      case SDLK_UP:
        selectPreviousLevel();
        break;
      case SDLK_DOWN:
        selectNextLevel();
        break;
    }
  }
}

void MenuScreen::update() {}

void MenuScreen::selectNextLevel() {
  m_selected_level = (m_selected_level + 1) % m_levels.size();
}

void MenuScreen::selectPreviousLevel() {
  m_selected_level = (m_selected_level - 1 + m_levels.size()) % m_levels.size();
}