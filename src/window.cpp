#include <SDL.h>

#include "window.h"
#include "const.h"

Window::Window() : m_window(SDL_CreateWindow("Breakout Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, 0), SDL_DestroyWindow),
                   m_renderer(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), SDL_DestroyRenderer)
{
  init();
}

Window::~Window()
{
  SDL_Quit();
}

void Window::init() const
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!m_window)
  {
    std::cerr << "Failed to open " << SCREEN_WIDTH << " x " << SCREEN_HEIGHT << " window: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!m_renderer)
  {
    std::cerr << "Failed to create renderer: " << SDL_GetError() << std::endl;
    exit(EXIT_FAILURE);
  }

  SDL_SetRenderDrawColor(m_renderer.get(), 255, 255, 255, 255);
}

void Window::run() const
{
  SDL_Event event;
  SDL_PollEvent(&event);
  render();
  while (SDL_WaitEvent(&event))
  {
    render();
    handle_events(event);
  }
}

void Window::render() const
{
  SDL_RenderClear(m_renderer.get());
  // Draw here
  SDL_RenderPresent(m_renderer.get());
}

void Window::handle_events(const SDL_Event &event) const
{
  switch (event.type)
  {
  case SDL_QUIT:
    exit(EXIT_SUCCESS);
    break;
  }
}