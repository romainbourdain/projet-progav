#include "screens/game-screen.h"
#include "screens/screen-manager.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

GameScreen::GameScreen(ScreenManager& screen_manager)
    : Screen(screen_manager) {}

void GameScreen::handle_events() {
  if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_ESCAPE)) {
    m_screen_manager.change_screen(
        std::make_shared<TitleScreen>(m_screen_manager));
  }
}

void GameScreen::update() {
  // Mise à jour de l'état de jeu
}

void GameScreen::render() {
  // Rendu de l'état de jeu
}