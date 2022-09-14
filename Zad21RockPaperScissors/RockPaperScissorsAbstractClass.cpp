#include "RockPaperScissorsAbstractClass.hpp"

int RockPaperScissorsAbstract::isRemis(RPS firstMove, RPS secondMove) const
{
	if (firstMove == RPS::PAPER && secondMove == RPS::PAPER) //osobna funkcja isRemis?
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
		return 0;
	}
	if (firstMove == RPS::ROCK && secondMove == RPS::ROCK)
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
		return 0;
	}
	if (firstMove == RPS::SCISSORS && secondMove == RPS::SCISSORS)
	{
		std::cout << "Remis, nikt nie dostaje punktu" << std::endl; //zrobić funkcję
		return 0;
	}
}
