#include "Game.h"

Game::Game() 
  : board({0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0})
{
  
}

void Game::start() {}
void Game::display() {}

std::array<int, 16> Game::getBoard() 
{ 
  return board; 
}

void Game::setBoard(int pos, int nbr) {}
void Game::move() {}
void Game::merge() {}
void Game::moveLeft() {}
void Game::moveRight() {}
void Game::moveUp() {}
void Game::moveDown() {}