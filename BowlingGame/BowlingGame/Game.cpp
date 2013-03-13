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
    if(isStrike(frameIndex)) 
    {
      gameScore +=(10 + strikeBonus(frameIndex));
      frameIndex++;
    }
    else if(isSpare(frameIndex))
    {
      gameScore += 10 + spareBonus(frameIndex);
      frameIndex += 2;
    }
    else 
    {
      gameScore += sumOfBallsInFrame(frameIndex);
      frameIndex += 2;
    }
  }
  return gameScore;
}

bool Game::isSpare(int frameIndex)
{
  return ((rolls[frameIndex] + rolls[frameIndex + 1]) == 10);
}

int Game::sumOfBallsInFrame(int frameIndex) {
    return rolls[frameIndex] + rolls[frameIndex + 1];
  }

int Game::spareBonus(int frameIndex) {
  return rolls[frameIndex + 2];
}

int Game::strikeBonus(int frameIndex) {
  return  rolls[frameIndex+1] + rolls[frameIndex+2];
}

bool Game::isStrike(int frameIndex) {
  return rolls[frameIndex] == 10;
}