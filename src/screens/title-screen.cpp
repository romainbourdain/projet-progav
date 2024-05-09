#include "screens/title-screen.h"
#include "sdl-wrapper.h"

#include <iostream>

TitleScreen::TitleScreen(SDL_Wrapper& sdl)
    : Screen(sdl),
      m_titleTexture(m_sdl.loadTexture("assets/images/title-screen.png")),
      m_titleFont(m_sdl.loadFont("../assets/fonts/Minecraft.ttf", 24)),
      m_scale(1.0f) {
  m_last_time = SDL_GetTicks();
}

void TitleScreen::render() const {
  int w = 800;
  int h = 600;

  m_sdl.drawTexture(m_titleTexture, 0, 0, w, h);
  m_sdl.drawText(m_titleFont, "Press Space to Start", w / 2, h - 20,
                 {255, 255, 255, 255});
}

void TitleScreen::update() {}
