#pragma once
#include <array>
#include <ctime>
#include <iostream>

class Game {
public:
  Game();
  void start();
  void display();
  void move();
  std::array<int, 16> getBoard();
  void setBoard(int pos, int nbr);

private:
  std::array<int, 16> board;
  void merge();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
};