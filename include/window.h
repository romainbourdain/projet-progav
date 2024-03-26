#pragma once

#include <SDL.h>
#include <iostream>

class Window
{
public:
  Window();
  ~Window();
  void init();
  void run();
  void render();
  void handle_events(const SDL_Event &event);

private:
  std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window;
  std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)> m_renderer;
};