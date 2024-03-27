#pragma once

class Brick {
 public:
  Brick();
  ~Brick();

 private:
  int m_x;
  int m_y;
  int m_width;
  int m_height;
  int m_solidity;
};