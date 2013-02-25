#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(BowlingGame)
{
};

TEST(BowlingGame, testGutterGame)
{
   Game* g = new Game;
   
   for(int i=0; i<20; i++)
   {
     g->roll(0);
   }

   LONGS_EQUAL(0, g->score());

   delete g;
}

TEST(BowlingGame, testAllOnes)
{
  Game* g = new Game;
  for(int i=0; i<20; i++)
  {
    g->roll(1);
  }

  LONGS_EQUAL(20, g->score());
}