#pragma once
#include <array>
#include <ctime>
#include <iostream>

class Game {
public:
  Game();
  bool play;
  void start();
  void display();
  void move();
  std::array<int, 16> getBoard();
  void setBoard(int pos, int nbr);
  void place();
  void checkPlay();

private:
  std::array<int, 16> board;
  void merge(int pos, int nbr);
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
};