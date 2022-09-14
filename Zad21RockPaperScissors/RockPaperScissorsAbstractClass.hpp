#pragma once
#include <iostream>

class RockPaperScissorsAbstract
{
protected:
	enum class RPS { ROCK = 1, PAPER, SCISSORS };
	int isRemis(RPS firstMove, RPS secondMove) const;
public:
	virtual void game() = 0;
	virtual ~RockPaperScissorsAbstract() = default;

};