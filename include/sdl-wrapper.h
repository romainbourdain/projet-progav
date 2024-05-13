#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>
#include <tuple>

using SDL_Window_ptr =
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using SDL_Renderer_ptr =
    std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;
using SDL_Surface_ptr =
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;

using SDL_Texture_ptr =
    std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
using TTF_Font_ptr = std::unique_ptr<TTF_Font, decltype(&TTF_CloseFont)>;

class SDL_Wrapper {
 private:
  SDL_Window_ptr m_window;
  SDL_Renderer_ptr m_renderer;

  TTF_Font_ptr m_font;

 public:
  SDL_Wrapper();
  ~SDL_Wrapper();

  void init(const std::string& title, int width, int height);
  void clear();
  void present();

  void loadFont(const std::string& fontPath, int fontSize);
  SDL_Texture_ptr loadTexture(const std::string& imagePath) const;
  void setRenderDrawColor(const SDL_Color color) const;

  void drawRect(int x, int y, int width, int height, SDL_Color color) const;
  void drawTexture(const SDL_Texture_ptr& texture, int x, int y, int width = 0,
                   int height = 0) const;
  void drawText(const std::string& text, int x, int y,
                const SDL_Color color) const;

  void getWindowSize(int& width, int& height) const;
};

using SDL_Wrapper_ptr = std::shared_ptr<SDL_Wrapper>;