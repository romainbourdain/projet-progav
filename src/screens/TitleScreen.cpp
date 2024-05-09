#include "screens/TitleScreen.h"
#include "SDLWrapper.h"
#include "utils.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>

TitleScreen::TitleScreen(SDLWrapper& sdl)
    : m_sdl(sdl),
      m_titleTexture(nullptr, SDL_DestroyTexture),
      m_titleFont(nullptr, TTF_CloseFont) {
  loadResources();
}

void TitleScreen::loadResources() {
  m_titleFont = m_sdl.loadFont("../assets/fonts/Minecraft.ttf", 24);
  m_titleTexture = m_sdl.loadTexture("assets/images/title-screen.png");
}

void TitleScreen::render() const {
  m_sdl.drawTexture(m_titleTexture, 0, 0);
  m_sdl.drawText(m_titleFont, "Press Space to Start", 800 / 2, 600 - 20,
                 {255, 255, 255});
}
