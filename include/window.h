#pragma once

#include <SDL2/SDL.h>
#include <iostream>
class Window {
 public:
  Window();
  ~Window();
  void clear() const;
  SDL_Renderer& get_renderer() const;

  void fill_background() const;
  void draw_rect(const SDL_Rect& rect, const SDL_Color& color) const;

 private:
  void init();
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};