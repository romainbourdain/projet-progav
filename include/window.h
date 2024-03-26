#pragma once

#include <SDL.h>
#include <iostream>

class Window {
 public:
  Window();
  ~Window();
  void init() const;
  void run() const;
  void render() const;
  void handle_events(const SDL_Event& event) const;

 private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};