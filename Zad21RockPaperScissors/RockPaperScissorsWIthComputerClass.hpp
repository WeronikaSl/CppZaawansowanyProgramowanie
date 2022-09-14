#pragma once
#include "RockPaperScissorsAbstractClass.hpp"
#include "PlayerClass.hpp"
#include "ComputerClass.hpp"

class RockPaperScissorsWithComputer : public virtual RockPaperScissorsAbstract
{
private:
	Player _player;
	Computer _computer;
	int whoGetsPoint(RPS playerMove, RPS computerMove);
	void displayWhoWon(unsigned short playersPoints, unsigned short computersPoints) const;
public:
	void game() override;
};