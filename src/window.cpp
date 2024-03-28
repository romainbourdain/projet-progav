#include <SDL.h>

#include "lib/const.h"
#include "lib/utils.h"

#include "window.h"

Window::Window()
    : m_window(nullptr, SDL_DestroyWindow),
      m_renderer(nullptr, SDL_DestroyRenderer) {
  init();
}

Window::~Window() {
  SDL_Quit();
}

SDL_Renderer& Window::get_renderer() const {
  return *m_renderer;
}

void Window::init() {
  // Initialize SDL
  AssertSDL(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == 0,
            "SDL could not initialize!");

  // Initialize window
  m_window.reset(SDL_CreateWindow(
      "Breakout Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, 0));
  AssertSDL(m_window != nullptr, "Window could not be created!");

  // Initialize renderer
  m_renderer.reset(
      SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED));
  AssertSDL(m_renderer != nullptr, "Renderer could not be created!");
}

void Window::clear() const {
  AssertSDL(SDL_RenderClear(m_renderer.get()) == 0,
            "Failed to clear the renderer!");
}

void Window::fill_background(const SDL_Color& background_color) const {
  AssertSDL(SDL_SetRenderDrawColor(m_renderer.get(), background_color.r,
                                   background_color.g, background_color.b,
                                   background_color.a) == 0,
            "Failed to set the renderer draw color!");
  SDL_RenderPresent(m_renderer.get());
}

void Window::draw_rect(const SDL_Rect& rect, const SDL_Color& color) const {
  AssertSDL(SDL_SetRenderDrawColor(m_renderer.get(), color.r, color.g, color.b,
                                   color.a) == 0,
            "Failed to set the renderer draw color!");
  AssertSDL(SDL_RenderFillRect(m_renderer.get(), &rect) == 0,
            "Failed to draw the rectangle!");
}