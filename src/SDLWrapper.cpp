#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <string>

#include "SDLWrapper.h"
#include "utils.h"

SDLWrapper::SDLWrapper()
    : m_window(nullptr, SDL_DestroyWindow), m_renderer(nullptr) {}

void SDLWrapper::init(const std::string& title, int width, int height) {
  ASSERT_AND_ERROR(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) == 0,
                   "SDL Init failed");

  // Create window
  m_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED, width, height,
                                  SDL_WINDOW_SHOWN));
  ASSERT_AND_ERROR(m_window != nullptr, "Window creation failed");

  // Create renderer
  m_renderer.reset(
      SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED),
      SDL_DestroyRenderer);
  ASSERT_AND_ERROR(m_renderer != nullptr, "Renderer creation failed");

  TTF_Init();
}

void SDLWrapper::clear() {
  SDL_RenderClear(m_renderer.get());
}

void SDLWrapper::present() {
  SDL_RenderPresent(m_renderer.get());
}

void SDLWrapper::drawRect(int x, int y, int width, int height,
                          const SDL_Color color) const {
  SDL_Rect rect = {x, y, width, height};
  setRenderDrawColor(color);
  SDL_RenderFillRect(m_renderer.get(), &rect);
}

void SDLWrapper::setRenderDrawColor(const SDL_Color color) const {
  SDL_SetRenderDrawColor(m_renderer.get(), color.r, color.g, color.b, color.a);
}

TTF_Font_ptr SDLWrapper::loadFont(const std::string& fontPath,
                                  int fontSize) const {
  TTF_Font_ptr font(TTF_OpenFont(fontPath.c_str(), fontSize), TTF_CloseFont);
  ASSERT_AND_ERROR(font != nullptr, SDL_GetError());
  return font;
}

SDL_Texture_ptr SDLWrapper::loadTexture(const std::string& imagePath) const {
  SDL_Surface_ptr surface(IMG_Load(imagePath.c_str()), SDL_FreeSurface);
  SDL_Texture_ptr texture(
      SDL_CreateTextureFromSurface(m_renderer.get(), surface.get()),
      SDL_DestroyTexture);
  return texture;
}

void SDLWrapper::drawTexture(const SDL_Texture_ptr& texture, int x,
                             int y) const {
  SDL_Rect rect = {x, y, 0, 0};
  ASSERT_AND_ERROR(
      SDL_QueryTexture(texture.get(), nullptr, nullptr, &rect.w, &rect.h) == 0,
      SDL_GetError());

  SDL_RenderCopy(m_renderer.get(), texture.get(), nullptr, &rect);
}

void SDLWrapper::drawText(const TTF_Font_ptr& font, const std::string& text,
                          int x, int y, SDL_Color color) const {
  SDL_Surface_ptr surface(TTF_RenderText_Solid(font.get(), text.c_str(), color),
                          SDL_FreeSurface);
  SDL_Texture_ptr texture(
      SDL_CreateTextureFromSurface(m_renderer.get(), surface.get()),
      SDL_DestroyTexture);
  SDL_Rect rect = {x, y, surface->w, surface->h};
  SDL_RenderCopy(m_renderer.get(), texture.get(), nullptr, &rect);
}