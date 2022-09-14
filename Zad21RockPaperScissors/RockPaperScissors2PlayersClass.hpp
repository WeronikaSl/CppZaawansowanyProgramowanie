#pragma once
#include "RockPaperScissorsAbstractClass.hpp"
#include "PlayerClass.hpp"
#include <stdlib.h>

class RockPaperScissors2Players : public virtual RockPaperScissorsAbstract
{
private:
	Player _player1;
	Player _player2;
	int whoGetsPoint(RPS player1Move, RPS player2Move);
	void displayWhoWon(unsigned short player1Points, unsigned short player2Points) const;

public:
	void game() override;
};