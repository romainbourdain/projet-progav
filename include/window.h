#pragma once

#include <SDL.h>
#include <iostream>
#include <memory>

class Window {
 public:
  Window();
  ~Window();

  SDL_Renderer& get_renderer() const;

  void clear() const;

  void fill_background(const SDL_Color& background_color) const;
  void draw_rect(const SDL_Rect& rect, const SDL_Color& color) const;

 private:
  void init();

  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};