#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(BowlingGame)
{
};

TEST(BowlingGame, testGutterGame)
{
   Game* g = new Game;
   delete g;
   for(int i=0; i>20; i++)
   {
     g.roll(0);
   }
}