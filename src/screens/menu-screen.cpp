#include "screens/menu-screen.h"
#include "config.h"
#include "screens/game-screen.h"
#include "screens/screen-manager.h"

#include <algorithm>
#include <filesystem>
#include <functional>
#include <iostream>
#include <unordered_map>

MenuScreen::MenuScreen(ScreenManager& screen_manager)
    : Screen(screen_manager), m_selected_level(0), m_is_key_pressed(true) {
  load_levels();
  load_assets();
  std::cout << "MenuScreen created" << std::endl;
}

void MenuScreen::load_assets() {
  m_font = SDL_Wrapper::load_font("assets/fonts/Minecraft.ttf", 24);
}

void MenuScreen::load_levels() {
  std::string level_directory = "levels/";
  for (const auto& entry :
       std::filesystem::directory_iterator(level_directory)) {
    if (entry.is_regular_file() && entry.path().extension() == ".lvl") {
      m_levels.push_back(entry.path().filename().string());
    }
  }

  std::sort(m_levels.begin(), m_levels.end());
}

void MenuScreen::handle_events() {
  static const std::unordered_map<SDL_Scancode, std::function<void()>>
      key_actions = {
          {SDL_SCANCODE_DOWN,
           [this]() {
             m_selected_level = (m_selected_level + 1) % m_levels.size();
           }},
          {SDL_SCANCODE_UP,
           [this]() {
             m_selected_level =
                 (m_selected_level - 1 + m_levels.size()) % m_levels.size();
           }},
          {SDL_SCANCODE_SPACE,
           [this]() {
             m_screen_manager.change_screen(std::make_shared<GameScreen>(
                 m_screen_manager, m_levels[m_selected_level]));
           }},
      };

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

void MenuScreen::update() {}

void MenuScreen::render() {
  SDL_Wrapper::render_text("Select a level", m_font, Config::WINDOW_WIDTH / 2,
                           50, Config::FOREGROUND_COLOR,
                           SDL_Wrapper::Origin::CENTER);

  for (size_t i = 0; i < m_levels.size(); i++) {
    std::string level_name = m_levels[i];
    if (i == static_cast<size_t>(m_selected_level)) {
      level_name = "> " + level_name;
    }
    SDL_Wrapper::render_text(level_name, m_font, Config::WINDOW_WIDTH / 2,
                             100 + i * 30, Config::FOREGROUND_COLOR,
                             SDL_Wrapper::Origin::CENTER);
  }
}