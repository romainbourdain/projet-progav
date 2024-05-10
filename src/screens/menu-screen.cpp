#include "screens/menu-screen.h"
#include "screens/title-screen.h"

MenuScreen::MenuScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl)
    : Screen(screen_manager, sdl),
      m_levels(),
      m_selected_level(0),
      m_font(m_sdl.loadFont("../assets/fonts/Minecraft.ttf", 24)) {
  m_levels.push_back("Level 1");
  m_levels.push_back("Level 2");
  m_levels.push_back("Level 3");
  m_levels.push_back("Level 4");
  m_levels.push_back("Level 5");
}

void MenuScreen::render() const {
  for (int i = 0; i < m_levels.size(); i++) {
    m_sdl.drawText(m_font, m_levels[i], 400,
                   300 + i * 50 - m_levels.size() * 25, {255, 255, 255, 255});
    if (i == m_selected_level) {
      m_sdl.drawText(m_font, ">", 340, 300 + i * 50 - m_levels.size() * 25,
                     {255, 255, 255, 255});
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
      case SDLK_SPACE:
        m_screen_manager.changeScreen(
            std::make_shared<TitleScreen>(m_screen_manager, m_sdl));
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