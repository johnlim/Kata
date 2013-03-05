#include "CppUTest/TestHarness.h"
#include "Game.h"

TEST_GROUP(BowlingGame)
{
  Game g;

  void rollMany(int n, int pins)
  {
    for(int i=0; i<n; i++)
    {
      g.roll(pins);
    }
  }

  void rollSpare()
  {
    g.roll(5);
    g.roll(5);
  }
};


TEST(BowlingGame, testGutterGame)
{
  rollMany(20, 0);
  LONGS_EQUAL(0, g.score());
}

TEST(BowlingGame, testAllOnes)
{
  rollMany(20, 1);
  LONGS_EQUAL(20, g.score());
}

TEST(BowlingGame, testOneSpare)
{
  rollSpare();
  g.roll(3);
  rollMany(17,0);
  LONGS_EQUAL(16, g.score());
}

TEST(BowlingGame, testOneStrike)
{
  g.roll(10);
  g.roll(3);
  g.roll(4);
  rollMany(16,0);
  LONGS_EQUAL(24,g.score());
}