#include "screens/game-screen.h"
#include "config.h"
#include "screens/screen-manager.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

GameScreen::GameScreen(ScreenManager& screen_manager) : Screen(screen_manager) {
  m_title_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 24);
  m_subtitle_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 16);

  m_lives = SDL_Wrapper::load_texture("assets/images/lives.png");
  m_score = SDL_Wrapper::load_texture("assets/images/score.png");
}

void GameScreen::handle_events() {
  if (!m_game_manager.is_playing()) {
    if (SDL_Wrapper::is_key_pressed(SDL_SCANCODE_SPACE)) {
      m_game_manager.reset();
    }
    return;
  }
}

void GameScreen::update() {
  m_game_manager.update();
}

void GameScreen::render() {
  auto& paddle = m_game_manager.get_paddle();
  paddle.render();

  for (auto& ball : m_game_manager.get_balls()) {
    ball.render();
  }

  for (auto& brick : m_game_manager.get_bricks()) {
    if (!brick.is_destroyed())
      brick.render();
  }

  std::string score_text = std::to_string(m_game_manager.get_score());
  std::string lives_text = std::to_string(m_game_manager.get_lives());

  SDL_Wrapper::render_texture(m_score, 10, Config::WINDOW_HEIGHT - 15, 20, 20,
                              SDL_Wrapper::Origin::BOTTOM_LEFT);
  SDL_Wrapper::render_texture(m_lives, Config::WINDOW_WIDTH - 10,
                              Config::WINDOW_HEIGHT - 15, 20, 20,
                              SDL_Wrapper::Origin::BOTTOM_RIGHT);

  SDL_Wrapper::render_text(score_text, m_title_font, 35,
                           Config::WINDOW_HEIGHT - 10, Config::FOREGROUND_COLOR,
                           SDL_Wrapper::Origin::BOTTOM_LEFT);
  SDL_Wrapper::render_text(lives_text, m_title_font, Config::WINDOW_WIDTH - 35,
                           Config::WINDOW_HEIGHT - 10, Config::FOREGROUND_COLOR,
                           SDL_Wrapper::Origin::BOTTOM_RIGHT);

  if (!m_game_manager.is_playing()) {
    SDL_Wrapper::draw_rect(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2,
                           400, 150, Config::BACKGROUND_COLOR, true,
                           SDL_Wrapper::Origin::CENTER);
    SDL_Wrapper::draw_rect(Config::WINDOW_WIDTH / 2, Config::WINDOW_HEIGHT / 2,
                           400, 150, Config::FOREGROUND_COLOR, false,
                           SDL_Wrapper::Origin::CENTER);

    SDL_Wrapper::render_text(
        "Game Over", m_title_font, Config::WINDOW_WIDTH / 2,
        Config::WINDOW_HEIGHT / 2 - 30, Config::FOREGROUND_COLOR,
        SDL_Wrapper::Origin::CENTER);
    SDL_Wrapper::render_text(
        "Press SPACE to restart", m_subtitle_font, Config::WINDOW_WIDTH / 2,
        Config::WINDOW_HEIGHT / 2 + 15, Config::FOREGROUND_COLOR,
        SDL_Wrapper::Origin::CENTER);
    SDL_Wrapper::render_text(

        "Press ESCAPE to leave", m_subtitle_font, Config::WINDOW_WIDTH / 2,
        Config::WINDOW_HEIGHT / 2 + 40, Config::FOREGROUND_COLOR,
        SDL_Wrapper::Origin::CENTER);
  }
}