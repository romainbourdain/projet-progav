#pragma once

#include <SDL.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>

#include "utils.h"

using SDL_Window_ptr =
    std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
using SDL_Renderer_ptr = std::shared_ptr<SDL_Renderer>;
using SDL_Surface_ptr =
    std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
using SDL_Texture_ptr = std::shared_ptr<SDL_Texture>;
using TTF_Font_ptr = std::shared_ptr<TTF_Font>;

class SDLWrapper {
 private:
  SDL_Window_ptr m_window;
  SDL_Renderer_ptr m_renderer;

 public:
  SDLWrapper();

  void init(const std::string& title, int width, int height);
  void clear();
  void present();

  TTF_Font_ptr loadFont(const std::string& fontPath, int fontSize) const;
  SDL_Texture_ptr loadTexture(const std::string& imagePath) const;
  void setRenderDrawColor(const SDL_Color color) const;

  void drawRect(int x, int y, int width, int height, SDL_Color color) const;
  void drawTexture(const SDL_Texture_ptr& texture, int x, int y) const;
  void drawText(const TTF_Font_ptr& font, const std::string& text, int x, int y,
                const SDL_Color color) const;
};

using SDLWrapper_ptr = std::shared_ptr<SDLWrapper>;