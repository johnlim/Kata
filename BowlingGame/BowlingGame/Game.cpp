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
  int frameIndex = 0;
  for(int frame = 0; frame < 10; frame++)
  {
    if(rolls[frameIndex] == 10) //strike
    {
      gameScore +=(10 + rolls[frameIndex+1] + rolls[frameIndex+2]);
      frameIndex++;
    }
    else if(isSpare(frameIndex))
    {
      gameScore = 10 + rolls[frameIndex + 2];
      frameIndex += 2;
    }
    else 
    {
      gameScore += rolls[frameIndex] + rolls[frameIndex+1];
      frameIndex += 2;
    }
  }
  return gameScore;
}

bool Game::isSpare(int frameIndex)
{
  return ((rolls[frameIndex] + rolls[frameIndex + 1]) == 10);
}