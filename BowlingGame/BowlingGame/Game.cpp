#include "Game.h"

Game::Game()
      :gameScore(0)
{

}
void Game::roll(int pins)
{
  gameScore += pins;
}

int Game::score()
{
  return gameScore;
}