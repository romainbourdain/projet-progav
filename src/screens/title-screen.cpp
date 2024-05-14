#include "screens/title-screen.h"
#include <iostream>
#include "config.h"
#include "screens/game-screen.h"
#include "screens/screen-manager.h"
#include "sdl-wrapper.h"

TitleScreen::TitleScreen(ScreenManager& screen_manager)
    : Screen(screen_manager),
      m_subtitle_text("Press SPACE to start"),
      m_text_color({255, 255, 255, 255}) {
  load_assets();
}

void TitleScreen::load_assets() {
  m_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 22);
  m_background = SDL_Wrapper::load_texture("assets/images/title-screen.png");
}

void TitleScreen::handle_events() {
  if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_SPACE)) {
    m_screen_manager.change_screen(
        std::make_shared<GameScreen>(m_screen_manager));
  }
}

void TitleScreen::update() {
  // Mise à jour de l'écran titre
}

void TitleScreen::render() {

  SDL_Wrapper::render_texture(m_background, 0, 0, Config::WINDOW_WIDTH,
                              Config::WINDOW_HEIGHT);

  int subtitle_x = Config::WINDOW_WIDTH / 2;
  int subtitle_y = Config::WINDOW_HEIGHT - 50;
  SDL_Wrapper::render_text(m_subtitle_text, m_font, subtitle_x, subtitle_y,
                           m_text_color, SDL_Wrapper::Origin::CENTER);
}
