#include "Game.h"

int main() {
  Game game;
  game.start();
  while (game.play) {
    game.display();
    game.move();
    game.place();
  }
  return 0;
}