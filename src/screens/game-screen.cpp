#include "screens/game-screen.h"
#include "screen-manager.h"

GameScreen::GameScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl,
                       int level)
    : Screen(screen_manager, sdl), m_level(level) {
  // initialize brick grid
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 10; j++) {
      m_bricks.push_back(
          std::make_unique<Brick>(sdl, 50 + j * 50, 50 + i * 20, 50, 20, 1));
    }
  }
}

void GameScreen::render() const {
  for (const auto& brick : m_bricks) {
    brick->render();
  }
}

void GameScreen::update() {}

void GameScreen::handleEvent(const SDL_Event& event) {}