#include "game-engine.h"

#include <SDL.h>
#include <memory>
#include <string>

GameEngine::GameEngine(const std::string& title, int width, int height)
    : m_running(false), m_sdl(std::make_unique<SDL_Wrapper>()) {
  m_sdl->init(title, width, height);

  m_screenManager = std::make_unique<ScreenManager>(*m_sdl);
  m_screenManager->init();
  m_running = true;
}

void GameEngine::run() {
  SDL_Event event;
  while (m_running) {
    // Handle events
    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_QUIT) {
        m_running = false;
        std::exit(EXIT_SUCCESS);
      }
      m_screenManager->handleEvent(event);
    }

    m_sdl->clear();
    m_screenManager->update();
    m_screenManager->render();
    m_sdl->present();
  }
}
