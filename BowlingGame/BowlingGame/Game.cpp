#include "Game.h"

Game::Game()
      :currentRoll(0)
{
  for(int i=0; i<(sizeof(rolls)/sizeof(int)); i++)
  {
    rolls[i] = 0;
  }
}
void Game::roll(int pins)
{
  rolls[currentRoll++] = pins;
}

int Game::score()
{
  int gameScore = 0;
  int i = 0;
  for(int frame = 0; frame < 10; frame++)
  {
    if((rolls[i] + rolls[i + 1]) == 10) //spare
    {
      gameScore = 10 + rolls[i + 2];
      i += 2;
    }
    else 
    {
      gameScore += rolls[i] + rolls[i+1];
      i += 2;
    }
  }
  return gameScore;
}