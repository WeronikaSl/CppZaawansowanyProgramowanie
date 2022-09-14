#pragma once
#include "RockPaperScissorsAbstractClass.hpp"
#include "PlayerClass.hpp"
#include "ComputerClass.hpp"
#include <memory>

class RockPaperScissorsWithComputer : public RockPaperScissorsAbstract
{
private:
	Player _player;
	Computer _computer;
	void whoGetsPoint(RPS playerMove, RPS computerMove);
	void displayWhoWon(unsigned short playersPoints, unsigned short computersPoints);
public:
	void game() override;
};