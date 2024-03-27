#include <SDL.h>

#include "const.h"
#include "utils.h"
#include "window.h"

Window::Window()
    : m_window(nullptr, SDL_DestroyWindow),
      m_renderer(nullptr, SDL_DestroyRenderer) {
  init();
}

Window::~Window() {
  SDL_Quit();
}

void Window::init() {

  // Initialize SDL
  ASSERT_SDL(SDL_Init(SDL_INIT_VIDEO) == 0, "SDL could not initialize!");

  // Initialize window
  m_window.reset(SDL_CreateWindow("Breakout Game", SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, 0));
  ASSERT_SDL(m_window, "Window could not be created!");

  // Initialize renderer
  m_renderer.reset(
      SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED));
  ASSERT_SDL(m_renderer, "Renderer could not be created!");
}

void Window::run() const {
  SDL_Event event;
  SDL_PollEvent(&event);
  render();
  while (SDL_WaitEvent(&event)) {
    render();
    handle_events(event);
  }
}

void Window::render() const {
  SDL_RenderClear(m_renderer.get());
  // Draw here
  SDL_RenderPresent(m_renderer.get());
}

void Window::handle_events(const SDL_Event& event) const {
  switch (event.type) {
    case SDL_QUIT:
      exit(EXIT_SUCCESS);
      break;
  }
}