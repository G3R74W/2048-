#include "Game.h"

Game::Game()
    : board({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}), play(true),
      _moves(0), _score(0) {}

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
void Game::place() {
  int pos;
  bool place = false;
  srand(time(0));
  while (!place) {
    pos = rand() % 15;
    if (board[pos] == 0) {
      place = true;
    }
  }
  board[pos] = 2;
}
void Game::display() {
  std::cout << "---------------------------------------" << std::endl;
  // display score and number of moves
  std::cout << "score : " << _score << std::endl;
  std::cout << "number of moves : " << _moves << std::endl;
  std::cout << "\n\n";
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
        if (board[k] != 0) {
          std::cout << "|  " << board[k] << "  |";
        } else {
          std::cout << "|     |";
        }
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
  std::cout << "---------------------------------------" << std::endl;
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
    _moves++;
    moveLeft();
    break;
  case 'd':
    std::cout << "right" << std::endl;
    _moves++;
    moveRight();
    break;
  case 'z':
    std::cout << "up" << std::endl;
    _moves++;
    moveUp();
    break;
  case 's':
    std::cout << "down" << std::endl;
    _moves++;
    moveDown();
    break;
  }
}
void Game::merge(int pos, int nbr) {
  setBoard(pos, nbr);
  _score += nbr;
}

void Game::moveLeft() {
  int k = 3;
  // count the number of merges made
  // only one merge is allowed
  int mergeCntr;
  for (int i = 0; i < 4; i++) {
    mergeCntr = 0;
    for (int j = 0; k - j > k - 3; j++) {
      if (board[k - (j + 1)] == 0 && board[k - j] != 0) {
        setBoard(k - (j + 1), board[k - j]);
        setBoard(k - j, 0);
      }
      if (board[k - (j + 1)] == board[k - j] && board[k - (j + 1)] != 0) {
        int pos, nbr, setPos;
        if (board[k - (j + 2)] == board[k - (j + 1)] &&
            board[k - (j + 2)] != 0) {
          pos = k - (j + 2);
          nbr = 2 * board[k - (j + 1)];
          setPos = k - (j + 1);
        } else {
          pos = k - (j + 1);
          nbr = 2 * board[k - j];
          setPos = k - j;
        }
        if (mergeCntr == 0) {
          merge(pos, nbr);
          setBoard(setPos, 0);
          mergeCntr++;
        }
      }
    }
    k += 4;
  }
}
void Game::moveRight() {
  int k = 0;
  int mergeCntr;
  for (int i = 0; i < 4; i++) {
    mergeCntr = 0;
    for (int j = 0; k + j < k + 3; j++) {
      if (board[k + (j + 1)] == 0 && board[k + j] != 0) {
        setBoard(k + (j + 1), board[k + j]);
        setBoard(k + j, 0);
      }
      if (board[k + (j + 1)] == board[k + j] && board[k + (j + 1)] != 0) {
        int pos = k + (j + 1);
        int nbr = 2 * board[k + j];
        if (mergeCntr == 0) {
          merge(pos, nbr);
          setBoard(k + j, 0);
          mergeCntr++;
          j = 0;
        }
      }
    }
    k += 4;
  }
}
void Game::moveUp() {
  int k = 12;
  int mergeCntr;
  for (int i = 0; i < 4; i++) {
    mergeCntr = 0;
    for (int j = 0; k - j > k - 12; j += 4) {
      if (board[k - (j + 4)] == 0 && board[k - j] != 0) {
        setBoard(k - (j + 4), board[k - j]);
        setBoard(k - j, 0);
      }
      if (board[k - (j + 4)] == board[k - j] && board[k - (j + 4)] != 0) {
        int pos = k - (j + 4);
        int nbr = 2 * board[k - j];
        if (mergeCntr == 0) {
          merge(pos, nbr);
          setBoard(k - j, 0);
          mergeCntr++;
        }
      }
    }
    k++;
  }
}
void Game::moveDown() {
  int k = 0;
  int mergeCntr;
  for (int i = 0; i < 4; i++) {
    mergeCntr = 0;
    for (int j = 0; k + j < k + 12; j += 4) {
      if (board[k + (j + 4)] == 0 && board[k + j] != 0) {
        setBoard(k + (j + 4), board[k + j]);
        setBoard(k + j, 0);
      }
      if (board[k + (j + 4)] == board[k + j] && board[k + (j + 4)] != 0) {
        int pos = k + (j + 4);
        int nbr = 2 * board[k + j];
        if (mergeCntr == 0) {
          merge(pos, nbr);
          setBoard(k + j, 0);
          mergeCntr++;
        }
      }
    }
    k++;
  }
}

void Game::checkPlay() {
  // checks if the game is not lost or if there is a win
  for (int i = 0; i < 16; i++) {
    if (board[i] == 2048) {
      play = false;
    }
    if (board[i] != 0) {
      play = false;
    } else {
      play = true;
    }
    if (play) {
      break;
    }
  }
}