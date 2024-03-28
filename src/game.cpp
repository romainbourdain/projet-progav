#include <SDL2/SDL.h>

#include "brick.h"
#include "const.h"
#include "game.h"
#include "utils.h"

Game::Game() : m_window() {
  m_bricks.push_back(std::make_shared<Brick>(100, 100));
}

Game::~Game() {}

void Game::run() const {
  SDL_Event event;
  while (true) {
    while (SDL_PollEvent(&event)) {
      handle_events(event);
    }
    update();
    render();
  }
}

void Game::handle_events(const SDL_Event& event) const {
  switch (event.type) {
    case SDL_QUIT:
      SDL_Quit();
      exit(EXIT_SUCCESS);
    default:
      break;
  }
}

void Game::update() const {}

void Game::render() const {
  m_window.clear();

  for (const auto& brick : m_bricks) {
    brick->draw(m_window);
  }

  m_window.fill_background(Constants::BACKGROUND_COLOR);
}