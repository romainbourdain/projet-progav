#pragma once

#include <memory>
#include <vector>

#include "entities/ball.h"
#include "entities/brick.h"
#include "entities/paddle.h"
#include "screens/screen.h"

class GameScreen : public Screen {
 private:
  int m_level;
  std::vector<std::unique_ptr<Brick>> m_bricks;
  BrickShape m_brick_shape;

  // Paddle m_paddle;
  // Ball m_ball;

 public:
  explicit GameScreen(ScreenManager& screen_manager, SDL_Wrapper& sdl,
                      int level);

  void render() const override;
  void update() override;
  void handleEvent(const SDL_Event& event) override;
};