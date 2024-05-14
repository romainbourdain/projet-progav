#include "screens/title-screen.h"
#include <iostream>
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
  int window_width = SDL_Wrapper::get_window_width();
  int window_height = SDL_Wrapper::get_window_height();

  SDL_Wrapper::render_texture(m_background, 0, 0, window_width, window_height);

  int subtitle_x = window_width / 2;
  int subtitle_y = window_height - 50;
  SDL_Wrapper::render_text(m_subtitle_text, m_font, subtitle_x, subtitle_y,
                           m_text_color, SDL_Wrapper::Origin::CENTER);
}
