#include <SDL2/SDL.h>

#include "lib/const.h"
#include "lib/utils.h"

#include "brick.h"
#include "game.h"

Game::Game() : m_window(), m_running(true) {
  generate_bricks();
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

void Game::generate_bricks() {
  for (int i = 0; i < Constants::BRICKS_PER_ROW; ++i) {
    for (int j = 0; j < Constants::BRICKS_PER_COL; ++j) {
      int index_color = rand() % Constants::BRICK_COLORS.size();
      SDL_Color brick_color = Constants::BRICK_COLORS[index_color];
      m_bricks.push_back(std::make_shared<Brick>(Constants::BRICK_WIDTH * i,
                                                 Constants::BRICK_HEIGHT * j,
                                                 brick_color));
    }
  }
}