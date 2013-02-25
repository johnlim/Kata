#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(BowlingGame)
{
  Game g;
};

TEST(BowlingGame, testGutterGame)
{
   for(int i=0; i<20; i++)
   {
     g.roll(0);
   }

   LONGS_EQUAL(0, g.score());
}

TEST(BowlingGame, testAllOnes)
{
  for(int i=0; i<20; i++)
  {
    g.roll(1);
  }

  LONGS_EQUAL(20, g.score());
}