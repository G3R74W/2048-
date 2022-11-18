#include <array>
#include <ctime>
#include <iostream>

class Game {
public:
  Game();
  void start();
  void display(std::array<int, 16> _board);
  void move();

private:
  std::array<int, 16> board();
  std::array<int, 16> getBoard();
  void setBoard(int pos, int nbr);
  void merge();
  void moveLeft();
  void moveRight();
  void moveUp();
  void moveDown();
};