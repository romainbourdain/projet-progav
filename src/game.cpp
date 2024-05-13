#include "game.h"
#include "screens/title-screen.h"
#include "sdl-wrapper.h"

Game::Game(const std::string& title, int width, int height)
    : m_is_running(true) {
  SDL_Wrapper::init(title, width, height);
  m_screen_manager.change_screen(
      std::make_shared<TitleScreen>(m_screen_manager));
}

Game::~Game() {
  SDL_Wrapper::quit();
}

void Game::run() {
  while (m_is_running) {
    handle_events();
    update();
    render();
  }
}

void Game::quit() {
  m_is_running = false;
}

void Game::handle_events() {
  SDL_Event event;

  while (SDL_PollEvent(&event)) {
    if (event.type == SDL_QUIT) {
      quit();
    }
  }
  SDL_Wrapper::process_input();
  m_screen_manager.handle_events();
}

void Game::update() {
  m_screen_manager.update();
}

void Game::render() {
  SDL_Wrapper::clear();
  m_screen_manager.render();
  SDL_Wrapper::present();
}