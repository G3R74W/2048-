#include "Game.h"

Game::Game()
    : board({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), play(true) {}

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
  // std::array<int, 16> board = getBoard();
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

void Game::move() {
  char direction;
  std::cout << "direction ?" << std::endl;
  std::cin >> direction;

  switch (direction) {
  case 'q':
    std::cout << "left" << std::endl;
    moveLeft();
    break;
  case 'd':
    std::cout << "right" << std::endl;
    moveRight();
    break;
  case 'z':
    std::cout << "up" << std::endl;
    moveUp();
    break;
  case 's':
    std::cout << "down" << std::endl;
    moveDown();
    break;
  }
}
void Game::merge(int pos, int nbr) { setBoard(pos, nbr); }

void Game::moveLeft() {
  int k = 3;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; k - j > k - 3; j++) {
      if (board[k - (j + 1)] == 0 && board[k - j] != 0) {
        setBoard(k - (j + 1), board[k - j]);
        setBoard(k - j, 0);
      }
      if (board[k - (j + 1)] == board[k - j] && board[k - (j + 1)] != 0) {
        int pos = k - (j + 1);
        int nbr = 2 * board[k - j];
        merge(pos, nbr);
        setBoard(k - j, 0);
      }
    }
    k += 4;
  }
}
void Game::moveRight() {
  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; k + j < k + 3; j++) {
      if (board[k + (j + 1)] == 0 && board[k + j] != 0) {
        setBoard(k + (j + 1), board[k + j]);
        setBoard(k + j, 0);
      }
      if (board[k + (j + 1)] == board[k + j] && board[k + (j + 1)] != 0) {
        int pos = k + (j + 1);
        int nbr = 2 * board[k + j];
        merge(pos, nbr);
        setBoard(k + j, 0);
      }
    }
    k += 4;
  }
}
void Game::moveUp() {
  int k = 12;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; k - j > k - 12; j += 4) {
      if (board[k - (j + 4)] == 0 && board[k - j] != 0) {
        setBoard(k - (j + 4), board[k - j]);
        setBoard(k - j, 0);
      }
      if (board[k - (j + 4)] == board[k - j] && board[k - (j + 4)] != 0) {
        int pos = k - (j + 4);
        int nbr = 2 * board[k - j];
        merge(pos, nbr);
        setBoard(k - j, 0);
      }
    }
    k++;
  }
}
void Game::moveDown() {
  int k = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; k + j < k + 12; j += 4) {
      if (board[k + (j + 4)] == 0 && board[k + j] != 0) {
        setBoard(k + (j + 4), board[k + j]);
        setBoard(k + j, 0);
      }
      if (board[k + (j + 4)] == board[k + j] && board[k + (j + 4)] != 0) {
        int pos = k + (j + 4);
        int nbr = 2 * board[k + j];
        merge(pos, nbr);
        setBoard(k + j, 0);
      }
    }
    k++;
  }
}