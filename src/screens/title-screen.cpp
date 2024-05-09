#include "screens/title-screen.h"
#include "sdl-wrapper.h"

TitleScreen::TitleScreen(SDLWrapper& sdl)
    : m_sdl(sdl),
      m_titleTexture(m_sdl.loadTexture("assets/images/title-screen.png")),
      m_titleFont(m_sdl.loadFont("../assets/fonts/Minecraft.ttf", 24)) {}

void TitleScreen::render() const {
  m_sdl.drawTexture(m_titleTexture, 0, 0, 800, 600);
  m_sdl.drawText(m_titleFont, "Press Space to Start", 800 / 2, 600 - 20,
                 {255, 255, 255});
}
