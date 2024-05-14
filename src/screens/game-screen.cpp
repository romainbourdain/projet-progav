#include "screens/game-screen.h"
#include "config.h"
#include "screens/screen-manager.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

GameScreen::GameScreen(ScreenManager& screen_manager) : Screen(screen_manager) {
  m_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 24);
}

void GameScreen::handle_events() {}

void GameScreen::update() {
  m_game_manager.update();
}

void GameScreen::render() {
  auto& paddle = m_game_manager.get_paddle();
  paddle.render();

  for (auto& ball : m_game_manager.get_balls()) {
    ball->render();
  }

  for (auto& brick : m_game_manager.get_bricks()) {
    if (!brick->is_destroyed())
      brick->render();
  }

  std::string score_text =
      "Score: " + std::to_string(m_game_manager.get_score());
  std::string lives_text =
      "Lives: " + std::to_string(m_game_manager.get_lives());

  SDL_Wrapper::render_text(score_text, m_font, 10, Config::WINDOW_HEIGHT - 10,
                           Config::FOREGROUND_COLOR,
                           SDL_Wrapper::Origin::BOTTOM_LEFT);
  SDL_Wrapper::render_text(lives_text, m_font, Config::WINDOW_WIDTH - 10,
                           Config::WINDOW_HEIGHT - 10, Config::FOREGROUND_COLOR,
                           SDL_Wrapper::Origin::BOTTOM_RIGHT);
}