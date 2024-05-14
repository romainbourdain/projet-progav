#include "sdl-wrapper.h"
#include <algorithm>
#include <iostream>

SDL_Window_ptr SDL_Wrapper::s_window(nullptr, SDL_DestroyWindow);
SDL_Renderer_ptr SDL_Wrapper::s_renderer(nullptr, SDL_DestroyRenderer);

std::shared_ptr<std::vector<Uint8>> SDL_Wrapper::s_key_state;
Uint32 SDL_Wrapper::s_mouse_state = 0;
int SDL_Wrapper::s_mouse_x = 0;
int SDL_Wrapper::s_mouse_y = 0;

auto SDL_Wrapper::s_frame_last = std::chrono::steady_clock::now();
int SDL_Wrapper::s_frame_delay = 0;

void SDL_Wrapper::init(const std::string& title, int width, int height) {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    throw SDLException("SDL could not initialize! SDL_Error: " +
                       std::string(SDL_GetError()));
  }

  s_window.reset(SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED, width, height,
                                  SDL_WINDOW_SHOWN));
  if (!s_window) {
    throw SDLException("Window could not be created! SDL_Error: " +
                       std::string(SDL_GetError()));
  }

  s_renderer.reset(
      SDL_CreateRenderer(s_window.get(), -1, SDL_RENDERER_ACCELERATED));
  if (!s_renderer) {
    throw SDLException("Renderer could not be created! SDL_Error: " +
                       std::string(SDL_GetError()));
  }

  int imgFlags = IMG_INIT_PNG;
  if (!(IMG_Init(imgFlags) & imgFlags)) {
    throw SDLException("SDL_image could not initialize! SDL_image Error: " +
                       std::string(IMG_GetError()));
  }

  if (TTF_Init() == -1) {
    throw SDLException("SDL_ttf could not initialize! SDL_ttf Error: " +
                       std::string(TTF_GetError()));
  }

  int key_count;
  const Uint8* keys = SDL_GetKeyboardState(&key_count);
  s_key_state = std::make_shared<std::vector<Uint8>>(keys, keys + key_count);

  std::cout << "SDL initialized successfully." << std::endl;
}

void SDL_Wrapper::quit() {
  s_renderer.reset();
  s_window.reset();

  TTF_Quit();
  IMG_Quit();
  SDL_Quit();

  std::cout << "SDL quit successfully." << std::endl;
}

int SDL_Wrapper::get_window_width() {
  int width;
  SDL_GetWindowSize(s_window.get(), &width, nullptr);
  return width;
}

int SDL_Wrapper::get_window_height() {
  int height;
  SDL_GetWindowSize(s_window.get(), nullptr, &height);
  return height;
}

SDL_Texture_ptr SDL_Wrapper::load_texture(const std::string& path) {
  SDL_Texture_ptr texture(IMG_LoadTexture(s_renderer.get(), path.c_str()),
                          SDL_DestroyTexture);
  if (!texture) {
    throw SDLException("Failed to load texture: " + path +
                       " SDL_Error: " + std::string(SDL_GetError()));
  }
  return texture;
}

TTF_Font_ptr SDL_Wrapper::load_font(const std::string& path, int fontSize) {
  TTF_Font_ptr font(TTF_OpenFont(path.c_str(), fontSize), TTF_CloseFont);
  if (!font) {
    throw SDLException("Failed to load font: " + path +
                       " SDL_ttf Error: " + std::string(TTF_GetError()));
  }
  return font;
}

void SDL_Wrapper::render_texture(SDL_Texture_ptr texture, int x, int y,
                                 int width, int height, Origin origin) {
  SDL_Rect renderQuad = get_rect_with_origin(x, y, width, height, origin);
  if (SDL_RenderCopy(s_renderer.get(), texture.get(), nullptr, &renderQuad) !=
      0) {
    throw SDLException("Failed to render texture! SDL Error: " +
                       std::string(SDL_GetError()));
  }
}

void SDL_Wrapper::render_text(const std::string& text, TTF_Font_ptr& font,
                              int x, int y, SDL_Color color, Origin origin) {
  SDL_Surface_ptr surface(TTF_RenderText_Solid(font.get(), text.c_str(), color),
                          SDL_FreeSurface);
  if (!surface) {
    throw SDLException("Unable to render text surface! SDL_ttf Error: " +
                       std::string(TTF_GetError()));
  }

  SDL_Texture_ptr texture(
      SDL_CreateTextureFromSurface(s_renderer.get(), surface.get()),
      SDL_DestroyTexture);
  if (!texture) {
    throw SDLException(
        "Unable to create texture from rendered text! SDL Error: " +
        std::string(SDL_GetError()));
  }

  render_texture(texture, x, y, surface->w, surface->h, origin);
}

void SDL_Wrapper::draw_rect(int x, int y, int width, int height,
                            SDL_Color color, bool fill, Origin origin) {
  SDL_Rect rect = get_rect_with_origin(x, y, width, height, origin);
  SDL_SetRenderDrawColor(s_renderer.get(), color.r, color.g, color.b, color.a);
  if (fill) {
    if (SDL_RenderFillRect(s_renderer.get(), &rect) != 0) {
      throw SDLException("Failed to draw filled rectangle! SDL Error: " +
                         std::string(SDL_GetError()));
    }
  } else {
    if (SDL_RenderDrawRect(s_renderer.get(), &rect) != 0) {
      throw SDLException("Failed to draw rectangle! SDL Error: " +
                         std::string(SDL_GetError()));
    }
  }
}

void SDL_Wrapper::clear() {
  if (SDL_RenderClear(s_renderer.get()) != 0) {
    throw SDLException("Failed to clear renderer! SDL Error: " +
                       std::string(SDL_GetError()));
  }
}

void SDL_Wrapper::present() {
  SDL_RenderPresent(s_renderer.get());
}

SDL_Rect SDL_Wrapper::get_rect_with_origin(int x, int y, int width, int height,
                                           Origin origin) {
  if (origin == Origin::TOP_LEFT) {
    return {x, y, width, height};
  } else if (origin == Origin::CENTER) {
    return {x - width / 2, y - height / 2, width, height};
  } else {
    throw SDLException("Invalid Origin");
  }
}

void SDL_Wrapper::process_input() {
  s_mouse_state = SDL_GetMouseState(&s_mouse_x, &s_mouse_y);
  SDL_PumpEvents();

  const Uint8* keys = SDL_GetKeyboardState(nullptr);
  std::copy(keys, keys + s_key_state->size(), s_key_state->begin());
}

void SDL_Wrapper::limit_fps(int fps) {
  s_frame_delay = 1000 / fps;
  auto frame_time = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::steady_clock::now() - s_frame_last)
                        .count();
  if (frame_time < s_frame_delay) {
    SDL_Delay(s_frame_delay - frame_time);
  }
  s_frame_last = std::chrono::steady_clock::now();
}
