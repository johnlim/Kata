#include "Game.h"

Game::Game()
      :gameScore(0),
       currentRoll(0)
{
  for(int i=0; i<(sizeof(rolls)/sizeof(int)); i++)
  {
    rolls[i] = 0;
  }
}
void Game::roll(int pins)
{
  gameScore += pins;
  rolls[currentRoll++] = pins;
}

int Game::score()
{
  int gameScore = 0;
  for(int i=0; i<(sizeof(rolls)/sizeof(int)); i++)
  {
    gameScore += rolls[i];
  }
  return gameScore;
}