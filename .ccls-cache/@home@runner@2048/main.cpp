#include "Game.h"

int main() {
  std::cout << "test" << std::endl;
  Game game;
  game.start();
  while (game.play) {
    game.display();
    game.move();
    game.place();
    game.checkPlay();
  }
  return 0;
}