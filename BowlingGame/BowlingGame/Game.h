class Game
{
public:
  Game();
  void roll(int pins);
  int score();

private:
  int gameScore;
  enum{MaxNoOfRollsPerGame = 21};
  int rolls[MaxNoOfRollsPerGame];
  int currentRoll;
};