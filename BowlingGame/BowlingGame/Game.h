class Game
{
public:
  Game();
  void roll(int pins);
  int score();

private:
  enum{MaxNoOfRollsPerGame = 21};
  int rolls[MaxNoOfRollsPerGame];
  int currentRoll;

  bool isSpare(int frameIndex);
  int sumOfBallsInFrame(int frameIndex);
  int spareBonus(int frameIndex);
  int strikeBonus(int frameIndex);
};