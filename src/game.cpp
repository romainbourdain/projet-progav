#include <SDL.h>
#include <algorithm>

#include "lib/const.h"
#include "lib/utils.h"

#include "brick.h"
#include "game.h"

Game::Game() : m_running(true), m_window() {
  generate_bricks();
}

Game::~Game() {}

void Game::run() {
  SDL_Event event;
  while (m_running) {
    while (SDL_PollEvent(&event)) {
      handle_events(event);
    }
    update();
    render();
  }
}

void Game::handle_events(const SDL_Event& event) {
  switch (event.type) {
    case SDL_QUIT:
      m_running = false;
    default:
      break;
  }
}

void Game::update() const {}

void Game::render() const {
  m_window.clear();

  std::for_each(
      m_bricks.begin(), m_bricks.end(),
      [&window = m_window](const auto& brick) { brick->draw(window); });

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