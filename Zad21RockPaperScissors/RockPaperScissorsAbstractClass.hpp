#pragma once

class RockPaperScissorsAbstract
{
public:
	enum class RPS {ROCK, PAPER, SCISSORS};
	virtual void game() = 0;
	virtual ~RockPaperScissorsAbstract() = default;
};