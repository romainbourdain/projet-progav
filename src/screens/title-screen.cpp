#include "screens/title-screen.h"
#include "screens/game-screen.h"
#include "screens/screen-manager.h"
#include "sdl-wrapper.h"

TitleScreen::TitleScreen(ScreenManager& state_manager)
    : Screen(m_screen_manager) {}

void TitleScreen::handle_events() {
  if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_RETURN)) {
    m_screen_manager.change_screen(
        std::make_shared<GameScreen>(m_screen_manager));
  }
}

void TitleScreen::update() {
  // Mise à jour de l'écran titre
}

void TitleScreen::render() {
  // Rendu de l'état du titre
}