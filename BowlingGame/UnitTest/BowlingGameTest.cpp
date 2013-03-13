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

  void rollStrike() {
    g.roll(10);
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
  g.roll(1);
  g.roll(1);
  rollSpare();
  g.roll(3);  
  rollMany(16,0);
  LONGS_EQUAL(18, g.score());
}

TEST(BowlingGame, testOneStrike)
{
  rollStrike();
  g.roll(3);
  g.roll(4);
  rollMany(16,0);
  LONGS_EQUAL(24,g.score());
}