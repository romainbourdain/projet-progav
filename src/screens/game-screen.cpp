#include "screens/game-screen.h"
#include "config.h"
#include "screens/screen-manager.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

#include <functional>
#include <iostream>
#include <unordered_map>

GameScreen::GameScreen(ScreenManager& screen_manager, std::string& level_path)
    : Screen(screen_manager),
      m_game_manager(level_path),
      m_is_key_pressed(false) {
  m_title_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 24);
  m_subtitle_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 16);

  m_lives = SDL_Wrapper::load_texture("assets/images/lives.png");
  m_score = SDL_Wrapper::load_texture("assets/images/score.png");
}

void GameScreen::handle_events() {
  static const std::unordered_map<SDL_Scancode, std::function<void()>>
      key_actions = {{SDL_SCANCODE_ESCAPE,
                      [this]() {
                        if (m_game_manager.is_playing()) {
                          m_game_manager.pause();
                        }
                      }},
                     {SDL_SCANCODE_SPACE, [this]() {
                        if (!m_game_manager.is_playing()) {
                          if (m_game_manager.is_game_over()) {
                            m_game_manager.reset();
                          } else {
                            m_game_manager.resume();
                          }
                        }
                      }}};

  bool any_key_pressed = false;
  for (const auto& [key, action] : key_actions) {
    if (SDL_Wrapper::is_key_pressed(key)) {
      if (!m_is_key_pressed) {
        m_is_key_pressed = true;
        action();
      }
      any_key_pressed = true;
      break;
    }
  }

  if (!any_key_pressed) {
    m_is_key_pressed = false;
  }
}

void GameScreen::update() {
  m_game_manager.update();
}

void GameScreen::render() {
  m_game_manager.render();

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
    if (m_game_manager.is_game_over()) {
      SDL_Wrapper::render_text(
          "Game Over", m_title_font, Config::WINDOW_WIDTH / 2,
          Config::WINDOW_HEIGHT / 2 - 30, Config::FOREGROUND_COLOR,
          SDL_Wrapper::Origin::CENTER);
    } else {
      SDL_Wrapper::render_text("Paused", m_title_font, Config::WINDOW_WIDTH / 2,
                               Config::WINDOW_HEIGHT / 2 - 30,
                               Config::FOREGROUND_COLOR,
                               SDL_Wrapper::Origin::CENTER);
    }
    SDL_Wrapper::render_text(
        "Press SPACE to play", m_subtitle_font, Config::WINDOW_WIDTH / 2,
        Config::WINDOW_HEIGHT / 2 + 15, Config::FOREGROUND_COLOR,
        SDL_Wrapper::Origin::CENTER);
  }
}