#include "Game.h"

Game::Game() : board({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) {}

void Game::start() {
  // getting 2 different random numbers between 0 & 15 to determine where the
  // starting tiles are positionned
  srand(time(0));
  int pos1 = -1;
  int pos2 = -1;
  while (pos1 == pos2 && (pos1 || pos2 < 0)) {
    pos1 = rand() % 15;
    pos2 = rand() % 15;
  }
  setBoard(pos1, 2);
  setBoard(pos2, 2);
}

void Game::display() {
  std::array<int, 16> board = getBoard();
  // display score, number of moves made, full grid
  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      std::cout << "|-----|";
    }
    std::cout << "\n";
    for (int j = 0; j < 4; j++) {
      // setting up display correctly for each numbers
      if (board[k] < 10) {
        std::cout << "|  " << board[k] << "  |";
      }
      if (board[k] >= 10 && board[k] < 100) {
        std::cout << "| " << board[k] << "  |";
      }
      if (board[k] >= 100 && board[k] < 1000) {
        std::cout << "| " << board[k] << " |";
      }
      if (board[k] >= 1000) {
        std::cout << "|" << board[k] << " |";
      }
      k++;
    }
    std::cout << "\n";
    for (int j = 0; j < 4; j++) {
      std::cout << "|-----|";
    }
    std::cout << "\n";
  }
}

std::array<int, 16> Game::getBoard() { return board; }

void Game::setBoard(int pos, int nbr) { board[pos] = nbr; }

void Game::move() {}
void Game::merge() {}
void Game::moveLeft() {}
void Game::moveRight() {}
void Game::moveUp() {}
void Game::moveDown() {}